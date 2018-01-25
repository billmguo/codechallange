#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
 
template <typename T>
class Queue
{
private:
  queue q;
  mutex m;
  condition_variable cv;
public:
   void pop(T& item) {
    unique_lock<mutex> l(m);
    cv.wait(l, [](){return !q.empty()});
    item = q.front();
    q.pop();
    return item;
  }
  void push(const T& item) {
     unique_lock<mutex> l(m);
     q.push(item);
     l.unlock(m);
     cv.notify_one();
  }
  void push(T&& item)
  {
    unique_lock l(m);
    unique_lock<mutex> l(m);
    q.push(move(item));
    l.unlock();
    cond_.notify_one();
  }
};
