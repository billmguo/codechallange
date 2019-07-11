/*A frog is crossing a river. The river is divided into x units and at each unit there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.

Given a list of stones' positions (in units) in sorted ascending order, determine if the frog is able to cross the river by landing on the last stone. Initially, the frog is on the first stone and assume the first jump must be 1 unit.

If the frog's last jump was k units, then its next jump must be either k - 1, k, or k + 1 units. Note that the frog can only jump in the forward direction.

Note:

The number of stones is ≥ 2 and is < 1,100.
Each stone's position will be a non-negative integer < 231.
The first stone's position is always 0.
Example 1:

[0,1,3,5,6,8,12,17]

There are a total of 8 stones.
The first stone at the 0th unit, second stone at the 1st unit,
third stone at the 3rd unit, and so on...
The last stone at the 17th unit.

Return true. The frog can jump to the last stone by jumping 
1 unit to the 2nd stone, then 2 units to the 3rd stone, then 
2 units to the 4th stone, then 3 units to the 6th stone, 
4 units to the 7th stone, and 5 units to the 8th stone.
 */

class Solution {
public:
    bool canCross(vector<int>& stones) {
       
        if (stones.empty())
            return false;
        map<int, set<int>> m;
        for (int i = 0; i < stones.size(); ++i) {
            m[stones[i]] = set<int>();
        }
        m[0].insert(0);
        for (int i = 0; i < stones.size(); i++) {
            for (int step:m[stones[i]]) {
                for (int nexts = step - 1; nexts <= step + 1; nexts++) {
                    if (nexts && m.count(stones[i] + nexts)) {
                        m[stones[i] + nexts].insert(nexts);
                    }
                }
            }
        }
        return !m[stones.back()].empty();
    }
};


[LeetCode] Word Ladder 词语阶梯
 
/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;
        queue<string> q{{beginWord}};
        int res = 0;
        while (!q.empty()) {
            for (int k = q.size(); k > 0; --k) {
                string word = q.front(); q.pop();
                if (word == end) return res + 1;
                for (int i = 0; i < word.size(); ++i) {
                    string newWord = word;
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        newWord[i] = ch;
                        if (wordSet.count(newWord) && newWord != word) {
                            q.push(newWord);
                            wordSet.erase(newWord);
                        }   
                    }
                }
            }
            ++res;
        }
        return 0;
    }
};
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


Rotate K group 

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(-1), *pre = dummy, *cur = pre;
        dummy->next = head;
        int num = 0;
        while (cur = cur->next) ++num;
        while (num >= k) {
            cur = pre->next;
            for (int i = 1; i < k; ++i) {
                ListNode *t = cur->next;
                cur->next = t->next;
                t->next = pre->next;
                pre->next = t;
            }
            pre = cur;
            num -= k;
        }
        return dummy->next;
    }
};
