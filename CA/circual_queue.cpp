class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        length_ = k + 1; // to store k elements, we need (k+1) cells
        container_ = new int[length_];
        front_ = 0;
        rear_ = 0;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }else{
            container_[rear_] = value;
            rear_ = (rear_ + 1) % length_;
            return true;            
        }
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }else{
            front_ = (front_ + 1) % length_; // doesn't really delete this element
            return true;
        }
    }
    
    int Front() {
        if(isEmpty()) return -1;
        else return container_[front_];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        else return container_[rear_ - 1 < 0 ? length_ - 1 : rear_ - 1];
    }
    
    bool isEmpty() {
        return front_ == rear_;
    }
    
    bool isFull() {
        return ((rear_ + 1) % length_) == front_;
    }
    
private:
    int* container_;
    int front_;
    int rear_;
    int length_;
};
