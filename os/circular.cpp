ass CircularQueue
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
