class Semaphore {
public:
  Semaphore(int count = 0) : count_(count) {
  }
    
  void Set(int count){
      count_ = count;
  }
    
  void Signal() {
    std::unique_lock<std::mutex> lock(mutex_);
    ++count_;
    cv_.notify_one();
  }

  void Wait() {
    std::unique_lock<std::mutex> lock(mutex_);
    while(count_ <= 0){
        cv_.wait(lock);
    }
    --count_;
  }

private:
  std::mutex mutex_;
  std::condition_variable cv_;
  int count_;
}; 

/*limite the number to 4*/
class DiningPhilosophers {
public:
    DiningPhilosophers() {
        sem.Set(4);
    }
    
    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        int l = philosopher;
        int r = (philosopher+1)%5;
        sem.Wait();        
        
        lock[l].lock();
        lock[r].lock();
        pickLeftFork();
        pickRightFork()
        eat();
        putRightFork();
        lock[r].unlock();
        lock[l].unlock();
        sem.Signal();
    }
private:
    std::mutex lock[5];
    Semaphore sem;
};


/*task left and right chopstick */
class DiningPhilosophers {
public:
    DiningPhilosophers() {
    }
    
    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        int l = philosopher;
        int r = (philosopher+1)%5;
        lk.lock();        
        lock[l].lock();
        lock[r].lock();
        pickLeftFork();
        pickRightFork();
        lk.unlock();
        eat();
        putRightFork();
        putLeftFork();
        lock[l].unlock();
        lock[r].unlock();
    }
private:
    std::mutex lock[5];
    std::mutex lk;
};

/*odd pick up left/right and even pickup right/left*/



class DiningPhilosophers {
public:
    DiningPhilosophers() {
    }
    
    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        int l = philosopher;
        int r = (philosopher+1)%5;
        if (philosopher %  2 == 0) {
            lock[r].lock();
            lock[l].lock();
            pickRightFork();
            pickLeftFork();
            eat();
            putLeftFork();
            putRightFork();
            lock[l].lock();
            lock[r].lock();
        } else {
            lock[l].lock();
            lock[r].lock();
            pickRightFork();
            pickLeftFork();
            eat();
            putLeftFork();
            putRightFork();
            lock[r].lock();
            lock[l].lock();
        }
    }
private:
    vector<std::mutex> lock(n)
};

