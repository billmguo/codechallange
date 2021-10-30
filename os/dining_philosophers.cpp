方法一：当两边的叉子都可用时才拿
当某一个哲学家能够同时拿起左右两只叉子时，才让他拿，这样就能够保证不会因为每个科学家都只拿了一只叉子而导致死锁。

为了保证能够同时拿起，我们需要对拿叉子这一步骤进行加锁，保证哲学家能够同时拿起一双叉子，而不会拿了一边后另一边被人抢走

class DiningPhilosophers {
public:
    DiningPhilosophers() 
    {}

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) 
    {
        //对拿叉子进行这一流程进行加锁，保证其能同时拿起一双，而不会被其他人抢走
        _lock.lock();
        _fork[philosopher].lock();
        _fork[(philosopher + 1) % 5].lock();
		_lock.unlock();
		
		//拿起左右叉子
        pickLeftFork();	
        pickRightFork();

        eat();	//吃饭
        
		//放下左右叉子
        putLeftFork();
        putRightFork();
        
        //解锁，让其他人获取叉子
        _fork[philosopher].unlock();
        _fork[(philosopher + 1) % 5].unlock();
    }

private:
    mutex _lock;	
    mutex _fork[5];
};

方法二：限制就餐的哲学家数量
如果要保证至少有一个哲学家能够进餐，那么我们可以采用最简单粗暴的方法，限制人数，只要同时进餐的哲学家不超过四人时，即使在最坏情况下，也至少有一个哲学家能够拿到多出来的那一个叉子。

我们需要用到一个计数器来表示当前就餐的人数，为了保证线程安全我们需要用到一个互斥锁和一个条件变量对其进行保护

class DiningPhilosophers {
public:
    DiningPhilosophers()
        :_count(0)
    {}

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) 
    {
        
        unique_lock<mutex> lock(_mtx);
        _cond.wait(lock, [this]()->bool{
            return _count < 4;
        });    //当就餐人数不超过四人的时候允许拿叉子
        ++_count;

        _fork[philosopher].lock();
        _fork[(philosopher + 1) % 5].lock();
        pickLeftFork();
        pickRightFork();

        eat();

        putLeftFork();
        putRightFork();
        _fork[philosopher].unlock();
        _fork[(philosopher + 1) % 5].unlock();

        --_count;
        _cond.notify_one();	//就餐完成，让下一个人进来就餐
    }

private:
    mutex _fork[5];
    mutex _mtx;
    condition_variable _cond;
    int _count;
};

方法三：奇数先左后右，偶数先右后左
由于餐桌是一个如下图的圆环，如果我们此时规定奇数位的哲学家先拿左边的叉子，再拿右边的叉子。而偶数位的哲学家先拿右边的再拿左边的，
此时竞争情况如下图所示

class DiningPhilosophers {
public:
    DiningPhilosophers()
    {}

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) 
    {
        //如果是奇数则先抢左后抢右
        if(philosopher & 1)
        {
            _fork[philosopher].lock();
            _fork[(philosopher + 1) % 5].lock();
            pickLeftFork();
            pickRightFork();
        }
        //如果是偶数则先抢右后抢左
        else
        {
            _fork[(philosopher + 1) % 5].lock();
            _fork[philosopher].lock();
            pickRightFork();
            pickLeftFork();
            
        }
        eat();  //吃饭

        putLeftFork();  //放下叉子
        putRightFork();
        _fork[philosopher].unlock();
        _fork[(philosopher + 1) % 5].unlock();
    }
private:
    mutex _fork[5];
};
