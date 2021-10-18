class DiningPhilosophers {
public:
    std::mutex mutex;
    std::condition_variable cond;
    vector<int> isvalid;
    static constexpr int N = 5;
    DiningPhilosophers() {
        isvalid.resize(N, 1);
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        {
            std::unique_lock<std::mutex> lk(mutex);
            cond.wait(lk, [this, philosopher]() { 
                return isvalid[philosopher] && isvalid[(philosopher + 1) % N]; 
            });
            isvalid[philosopher] = 0; isvalid[(philosopher + 1) % N] = 0;
            pickLeftFork(); pickRightFork();
        }
        
        eat();
        
        {
            std::unique_lock<std::mutex> lk(mutex);
            putLeftFork(); putRightFork();
            isvalid[philosopher] = 1; isvalid[(philosopher + 1) % N] = 1;
            cond.notify_all();
        }
    }
};
