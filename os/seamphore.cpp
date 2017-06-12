#include <iostream>
#include <mutex>
#include <condition_variable>
using namespace std;

class semaphore{
private:
	mutex m;
	condition_variable cv;
	int count;
public:
	semaphore(int _count):count(count) {};
	void sem_post() {
		unique_lock<mutex> l(m);
		count++;
		cv.notify_one();
	}
	void sem_wait() {
		unique_lock<mutex> l(m);
		cv.wait(l,[&](){return count > 0;});
		count--;
	}
};
