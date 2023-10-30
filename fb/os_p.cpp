timer callback

#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

class Timer {
	std::atomic<bool> active{true};
	
    public:
        void setTimeout(auto function, int delay);
        void setInterval(auto function, int interval);
        void stop();

};

void Timer::setTimeout(auto function, int delay) {
    active = true;
    std::thread t([=]() {
        if(!active.load()) return;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        if(!active.load()) return;
        function();
    });
    t.detach();
}

void Timer::setInterval(auto function, int interval) {
    active = true;
    std::thread t([=]() {
        while(active.load()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(interval));
            if(!active.load()) return;
            function();
        }
    });
    t.detach();
}

void Timer::stop() {
    active = false;
}


   t.setInterval([&]() {
        cout << "Hey.. After each 1s..." << endl;
    }, 1000); 

    t.setTimeout([&]() {
        cout << "Hey.. After 5.2s. But I will stop the timer!" << endl;
        t.stop();
    }, 5200); 

allocate 2D 

class Solution {
public:
    int** my2DAlloc(int rows, int cols) {
        int header = rows * sizeof(int*);
        int data = rows * cols * sizeof(int*);
        int **rowptr = (int**)malloc(header + data);
        if (rowptr == NULL) return NULL;
        int *buf = (int*)(rowptr + rows);
        for (int i = 0; i < rows; ++i) {
            rowptr[i] = buf + i * cols;
        }
        return rowptr;
    }
};

int** my2DAlloc(int rows, int cols) {
    int **rowptr = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; ++i) {
        rowptr[i] = (int*)malloc(cols * sizeof(int));
    }
    return rowptr;
}

void my2DDealloc(int **rowptr, int rows) {
    for (int i = 0; i < rows; ++i) {
        free(rowptr[i]);
    }
    free(rowptr);
}

aligned alloc 

class Solution {
public:
    void* aligned_malloc(size_t required_bytes, size_t alignment) {
        void *p1;
        void **p2;
        int offset = alignment - 1 + sizeof(void*);
        if ((p1 = (void*)malloc(required_bytes + offset)) == NULL) {
            return NULL;
        }
        p2 = (void**)(((size_t)(p1) + offset) & ~(alignment - 1));
        p2[-1] = p1;
        return p2;
    }
    void aligned_free(void *p2) {
        void *p1 = ((void**)p2)[-1];
        free(p1);
    }
};


Write a method that takes a pointer to a Node structure as a parameter and
returns a complete copy of the passed in data structure. The Node data structure contains two pointers to other Nodes.

class Node {
public:
    Node *ptr1;
    Node *ptr2;
};

typedef unordered_map<Node*, Node*> NodeMap;

class Solution {
public:
    Node* copy_structure(Node *root) {
        NodeMap m;
        return copy_recursive(root, m);
    }
    Node* copy_recursive(Node *cur, NodeMap &m) {
        if (cur == nullptr) return nullptr;
        auto it = m.find(cur);
        if (it != m.end()) return it->second;
        Node *node = new Node;
        m[cur] = node;
        node->ptr1 = copy_recursive(cur->ptr1, m);
        node->ptr2 = copy_recursive(cur->ptr2, m);
        return node;
    }
};





