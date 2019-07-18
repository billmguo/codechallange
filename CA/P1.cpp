Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:

If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets may form at least one valid itinerary.
 

Example 1:
tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Return ["JFK", "MUC", "LHR", "SFO", "SJC"].

    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> res;
        stack<string> st{{"JFK"}};
        unordered_map<string, multiset<string>> m;
        for (auto t : tickets) {
            m[t.first].insert(t.second);
        }
        while (!st.empty()) {
            string t = st.top(); 
            if (m[t].empty()) {
                res.insert(res.begin(), t);
                for (auto a:res)
                	cout<<a<<" ";
                cout<<endl;
                st.pop();
            } else {
                st.push(*m[t].begin());
                m[t].erase(m[t].begin());
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> res;
        unordered_map<string, multiset<string>> m;
        for (auto a : tickets) {
            m[a.first].insert(a.second);
        }
        dfs(m, "JFK", res);
        return vector<string> (res.rbegin(), res.rend());
    }
    void dfs(unordered_map<string, multiset<string>>& m, string s, vector<string>& res) {
        while (m[s].size()) {
            string t = *m[s].begin();
            m[s].erase(m[s].begin());
            dfs(m, t, res);
        }
        res.push_back(s);
    }
};

    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> res;
        stack<string> st{{"JFK"}};
        unordered_map<string, multiset<string>> m;
        for (auto t : tickets) {
            m[t.first].insert(t.second);
        }
     
        while (!st.empty()) {
            string t = st.top(); 
            if (m[t].empty()) {
                res.insert(res.begin(), t);
                for (auto a:res)
                	cout<<a<<" ";
                cout<<endl;
                st.pop();
            } else {
                st.push(*m[t].begin());
                m[t].erase(m[t].begin());
            }
        }
        return res;
    }
};
[LeetCode] Product of Array Except Self 除本身之外的数组之积
 
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            res[i] = res[i - 1] * nums[i - 1];
        }
        int right = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            res[i] *= right;
            right *= nums[i];
        }
        return res;
    }
};


[LeetCode] Find Median from Data Stream 找出数据流的中位数
 

Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

Examples:

[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
For example:

add(1)
add(2)
findMedian() -> 1.5
add(3) 
findMedian() -> 2

class MedianFinder {
private:
    priority_queue<long> large;
    priority_queue<long, vector<long>, greater<long>> small;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    

    void addNum(int num) {
        large.push(num);
        small.push(large.top());
        large.pop();
        if (large.size() < small.size()) {
            large.push(small.top());
            small.pop();
        }
    }
    
    double findMedian() {
        return large.size() > small.size() ? large.top() : 0.5 *(small.top() + large.top());
    }
};

Design a circular queue

class MyCircularQueue {
private:
    vector<int> q;
    int len, head, tail;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        q = vector<int>(k, 0);
        head = tail = 0;
        len = k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull()) 
            return false;
        q[tail%len]=value;
        ++tail;
        return true;
        
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty())
            return false;
        ++head;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()) 
            return -1;
        return q[head%len];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()) 
            return -1;
        return q[(tail-1)%len];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return (head == tail);
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (tail- head == len);
    }
};

class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        size = k; head = k - 1; tail = 0; cnt = 0;
        data.resize(k);
    }
    bool enQueue(int value) {
        if (isFull()) return false;
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

