class Scheduler : boost::noncopyable
{
private:
    std::multimap<std::chrono::system_clock::time_point, std::function<void()>> tasks;
    std::mutex m;
    std::unique_ptr<std::thread> thread;
    std::condition_variable cv;
    bool run;

public:

    Scheduler():go_on(true)
    {
       thread = new thread([this]()){this->loop();};

    }
    ~Scheduler()
    {
        run = false;
        thead->join();
    }

    void ThreadLoop()
    {
        while(run)
        {
            std::function<void()> func;
            {
                std::unique_lock<std::mutex> lock(m);
                auto now = std::chrono::system_clock::now();
                if ( tasks.empty()==false && tasks.begin()->first <= now) {
                    func = tasks.begin()->second;
                    task.erase(tasks.begin());
                }
            }

            // Run tasks while unlocked so tasks can schedule new tasks
            func();

            {
                std::unique_lock<std::mutex> lock(m);
                cv.wait(l, [](!tasks.empty()));
                cv.sleep(task.begin()->first - now);
            }
        }
    }

    void ScheduleAt(std::chrono::system_clock::time_point & time, std::function<void()> func)
    {
        std::unique_lock<std::mutex> lock(m);
        auto it = tasks.insert(make_pair(time,func));
        if (it == tasks.begin())
            cv.notify_one();
    }

    void ScheduleEvery(std::chrono::system_clock::duration interval, std::function<void()> func)
    {
        std::function<void()> tfunc = [&]() {
                func();
                this->ScheduleEvery(interval, func);
        };
        ScheduleAt(now() + interval, waitFunc);
    }
};
