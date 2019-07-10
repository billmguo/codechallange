[LeetCode] 296. Best Meeting Point 最佳开会地点
 

A group of two or more people wants to meet and minimize the total travel distance. You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

Example:

Input: 

1 - 0 - 0 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0

Output: 6 

Explanation: Given three people living at (0,0), (0,4), and (2,2):
             The point (0,2) is an ideal meeting point, as the total travel distance 
             of 2+2+2=6 is minimal. So return 6.

class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
    	vector<int> rows, cols;
    	for (int i = 0; i < grid.size(); i++) {
    		for (int j = 0; j < grid[i].size();j++) {
    			if (grid[i][j] == 1) {
    				rows.push_back(i);
    				cols.push_back(j);
    			}
    		}
    	}
    	sort(cols.begin(),cols.end());
    	int res = 0, i = 0, j = rows.size() - 1;
        while(i < j) res += rows[j] - rows[i] + cols[j--] - cols[i++];
        return res;
    }
};

[LeetCode] Find K Closest Elements 寻找K个最近元素
 

Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

Example 1:

Input: [1,2,3,4,5], k=4, x=3
Output: [1,2,3,4]
 

Example 2:

Input: [1,2,3,4,5], k=4, x=-1
Output: [1,2,3,4]


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res = arr;
        while(res.size() > k) {
        	if (x - res.front() <= res.back() -x) {
        		res.pop_back();
        	}else
        		res.erase(res.begin());
        }
        return res;
    }
};

下面这种解法是论坛上的高分解法，用到了二分搜索法。其实博主最开始用的方法并不是帖子中的这两个方法，
虽然也是用的二分搜索法，但是下面这种方法更加巧妙一些，二分法的判定条件做了一些改变，
就可以直接找到要返回的k的数字的子数组的起始位置，感觉非常的神奇。每次比较的是mid位置和x的距离跟mid+k跟x的距离，
以这两者的大小关系来确定二分法折半的方向，最后找到最近距离子数组的起始位置，参见代码如下：


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - k;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (x - arr[mid] > arr[mid + k] - x) left = mid + 1;
            else right = mid;
        }
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};



Design HitCounter

class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {}
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        q.push(timestamp);
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
    	while(!q.empty() && timestamp - q.front() >= 300)
    		q.pop();
    	return q.size();
    }

private:
    queue<int> q;
};


LRU cache

class LRUCache {
private:
    list<pair<int,int>> cache;
    unordered_map<int, list<pair<int,int>>::iterator> m;

    int size;
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if (!m.count(key))
            return -1;
        movetohead(key);
        return m[key]->second;
    }
    
    void put(int key, int value) {
       if (m.count(key)) {
           m[key]->second = value;
           movetohead(key);
       } else {
          if (cache.size() >= size) {
                m.erase(cache.back().first);
                cache.pop_back();
          }  
          cache.push_front({key, value});
          m[key] = cache.begin();
       }
        
    }
    void movetohead(int key) {
        auto it = m[key];
        cache.push_front(*it);
        cache.erase(it);
        m[key] = cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
