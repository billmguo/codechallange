It all depends on how the list will be used. Just a few examples:

Reads are more common than writes - use separate read/write locks.
Average list is short - use copy-on-write array instead of linked list.
Average list is long - use more efficient search method.
Lots of threads access list - use mutex instead of spinlock to avoid wasted cycles.
Lots of elements is added/removed in bulk - use external lock.

	
int writers; // Number writer threads that want to enter the critical section (some or all of these may be blocked)
int writing; // Number of threads that are actually writing inside the C.S. (can only be zero or one)
int reading; // Number of threads that are actually reading inside the C.S.
// if writing !=0 then reading must be zero (and vice versa)

reader() {
    lock(&m)
    while (writers)
        cond_wait(&turn, &m)
    // No need to wait while(writing here) because we can only exit the above loop
    // when writing is zero
    reading++
    unlock(&m)

  // perform reading here

    lock(&m)
    reading--
    cond_broadcast(&turn)
    unlock(&m)
}

writer() {
    lock(&m)  
    writers++  
    while (reading || writing)   
        cond_wait(&turn, &m)  
    writing++  
    unlock(&m)  
    // perform writing here  
    lock(&m)  
    writing--  
    writers--  
    cond_broadcast(&turn)  
    unlock(&m)  
}
#include <condition_variable>
#include <mutex>

class ReaderWriter
{
public:
	ReaderWriter(): readers(0), writers(0), active_writers(0) { }
	void reader();
	void writer();
private:
	int readers, writers;
	int active_writers;
	std::mutex mtx;
	std::condition_variable readersQ, writersQ;
};

void ReaderWriter::reader()
{
	std::unique_lock<std::mutex> lck(mtx);
	while(writers > 0)
		readersQ.wait(lck);
	readers++;
	lck.unlock();
	
	// read here
	lck.lock();
	if(--readers == 0)
		writersQ.notify_one();
	lck.unlock();
}

void ReaderWriter::writer()
{
	std::unique_lock<std::mutex> lck(mtx);
	writers++;
	while(readers > 0 or active_writers > 0)
		writersQ.wait(lck);
	active_writers++;
	lck.unlock();
	// write here
	lck.lock();
	active_writers--;
	if(--writers != 0)
		writersQ.notify_one();
	else
		readersQ.notify_all();
	lck.unlock();
}
