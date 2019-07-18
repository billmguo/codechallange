Circual dequeue 

class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        size = k; head = k - 1; tail = 0, cnt = 0;
        data.resize(k);
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) return false;
        data[head] = value;
        head = (head - 1 + size) % size;
        ++cnt;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) return false;
        data[tail] = value;
        tail = (tail + 1)  % size;
        ++cnt;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) return false;
        head = (head + 1) % size;
        --cnt;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) return false;
        tail = (tail - 1 + size) % size;
        --cnt;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        return isEmpty() ? -1 : data[(head + 1) % size];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        return isEmpty() ? -1 : data[(tail - 1 + size) % size];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return cnt == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return cnt == size;
    }

private:
    vector<int> data;
    int size, head, tail, cnt;
};

[LeetCode] Design Circular Queue 设计环形队列

class Circualqueue{
	int size;
	int head, tail, cnt;
public:
	Circualqueue(int k) {
		size = k; head = k - 1;
		tail = 0; cnt = 0;
		data.resize(k);
	}
}
class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        size = k; head = k - 1;
        tail = 0; cnt = 0;
        data.resize(k);
    }
    bool enQueue(int value) {
        if (isFull()) return false;
        data
        data[tail] = value;
        tail = (tail + 1) % size;
        ++cnt;
        return true;
    }
    bool deQueue() {
        if (isEmpty()) return false;
        head = (head + 1) % size;
        --cnt;
        return true;
    }
    int Front() {
        return isEmpty() ? -1 : data[(head + 1) % size];
    }
    int Rear() {
        return isEmpty() ? -1 : data[(tail - 1 + size) % size];
    }
    bool isEmpty() {
        return cnt == 0;
    }
    bool isFull() {
        return cnt == size;
    }
    
private:
    vector<int> data;
    int size, cnt, head, tail;
};
