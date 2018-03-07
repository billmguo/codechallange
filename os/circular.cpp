template <class T>
class circular_buffer {
public:
	circular_buffer(size_t b_size)
	{
		buf.resize(b_size);
		size = b_size;
	}

	void put(T item)
	{
		unique_lock<mutex> l(m);
		if (isfull())
			cv. wait(l, !isfull());
		
		buf[tail] = item;
		tail = (tail  + 1 ) % size;

	}

	T get(void)
	{
		unique_lock<mutex> l(m);
		if (isempty())
			return T();

		//Read data and advance the tail (we now have a free space)
		auto val = buf[tail];
		tail = (tail + 1) % size;
		return val;
	}

	void reset(void)
	{
		unique_lock<mutex> l(m);
		head = tail;
	}

	bool isempty(void)
	{
		return head == tail;
	}

	bool full(void)
	{
		return ((tail + 1) % size) == head;
	}

	size_t size(void)
	{
		return size - 1;
	}

private:
	mutex m;
	condition_variable cv;
	vector<T> buf;
	size_t head= 0;
	size_t tail = 0;
	size_t size;
};

class CircularQueue
{
        int cap;
        int count = 0;
        int front = 0;
        int rear = 0;
        vector<int> arr;
public:
        void CircularQueue(int cap) {
            this.cap = cap;
            arr.resize(cap);
        }

        bool Enqueue(int item) {
            if (count == cap)
                return false;

            arr[rear] = item;
            rear = (rear + 1) % cap;
            ++count;
            return true;
		}

        int Dequeue() {
            if (count == 0)
               return -1;
		    auto ret = arr[front];
		    front = (front + 1) % cap;
 			--count;

            return ret;
        }
};      
