#include <vector>
#include <queue>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>

using namespace std;

class ThreadPool {
public:
    ThreadPool(size_t);
    template<class F, class... Args>
    auto enqueue(F&& f, Args&&... args) 
        -> future<typename result_of<F(Args...)>::type>;
    ~ThreadPool();
private:
    vector< thread > workers;
    queue<function<void()> > tasks;
    
    mutex m;
    condition_variable cv;
    bool stop;
};
 
// the constructor just launches some amount of workers
inline ThreadPool::ThreadPool(size_t threads): stop(false)
{
    for(size_t i = 0;i<threads;++i)
        workers.emplace_back(
            [this]
            {
                for(;;)
                {
                    function<void()> task;
                    {
                        unique_lock<mutex> l(this->queue_mutex);
                        this->condition.wait(l,[this]{ return this->stop || !this->tasks.empty(); });
                        if(this->stop && this->tasks.empty())
                            return;
                        task = move(this->tasks.front());
                        this->tasks.pop();
                    }
                    task();
                }
            }
        );
}

// add new work item to the pool
template<class F, class... Args>
auto ThreadPool::enqueue(F&& f, Args&&... args) -> future<typename result_of<F(Args...)>::type>
{
    using return_type = typename result_of<F(Args...)>::type;

    auto task = make_shared< packaged_task<return_type()> >(
            bind(forward<F>(f), forward<Args>(args)...)
        );
        
    future<return_type> res = task->get_future();
    {
        unique_lock<mutex> l(queue_mutex);
        if(stop)
            throw runtime_error("enqueue on stopped ThreadPool");
        tasks.emplace([task](){(*task)(); });
    }
    cv.notify_one();
    return res;
}

// the destructor joins all threads
inline ThreadPool::~ThreadPool()
{
    {
        unique_lock<mutex> lock(queue_mutex);
        stop = true;
    }
    cv.notify_all();
    for(auto &worker: workers)
        worker.join();
}
