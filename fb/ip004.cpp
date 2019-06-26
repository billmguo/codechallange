back tracer stack comparing
class Solution {
    public boolean backspaceCompare(String S, String T) {
        if (S == null || T == null) return S == T;
        int m = S.length(), n = T.length();
        int i = m - 1, j = n - 1;
        int cnt1 = 0, cnt2 = 0;//number of '#';
        while (i >= 0 || j >= 0) {
            while (i >= 0 && (S.charAt(i) == '#' || cnt1 > 0)) {
                if (S.charAt(i) == '#') cnt1++;
                else cnt1--;
                i--;
            }
            while (j >= 0 && (T.charAt(j) == '#' || cnt2 > 0)) {
                if (T.charAt(j) == '#') cnt2++;
                else cnt2--;
                j--;
            }
            if (i >= 0 && j >= 0 && S.charAt(i) == T.charAt(j)) {
                i--;
                j--;
            } else {
                return i == -1 && j == -1;
            }
        }
        return true;
    }
}
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string a = "", b = "";
        for(auto c: S) 
            c == '#' ? a.size() > 0 ? a.pop_back() : void() : a.push_back(c);
        for(auto c: T) c == '#' ? b.size() > 0 ? b.pop_back() : void() : b.push_back(c);
        return a == b;
    }
};


Insert into a Cyclic Sorted List

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (!head) {
            head = new Node(insertVal, NULL);
            head->next = head;
            return head;
        }
        Node *pre = head, *cur = pre->next;
        while (cur != head) {
            if (pre->val <= insertVal && cur->val >= insertVal)
                break;
            if (pre->val > cur->val && (pre->val <= insertVal || cur->val >= insertVal))
                break;
            pre = cur;
            cur = cur->next;
        }
        pre->next = new Node(insertVal, cur);
        return head;
        
    }
};


Given two strings A and B, find the minimum number of times A has to be repeated such that
 B is a substring of it. If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".

Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; 
and B is not a substring of A repeated two times ("abcdabcd").

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        string t = A;
        for (int i = 1; i <= B.size() / A.size() + 2; ++i) {
            if (t.find(B) != string::npos)
                return i;
            t += A;
        }
        return -1;
    }
};

Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

Example 1:

Input: [1,2,3,4,5], k=4, x=3
Output: [1,2,3,4]

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res = arr;
        while (res.size() > k) {
            if (x - res.front() <= res.back() - x) {
                res.pop_back();
            } else {
                res.erase(res.begin());
            }
        }
        return res;
    }
};


This question asks to find K closest elements to a given number x. Or, in other words,
we could remove (n - k) elements which are farthest from given number. For example, 
arr = [1,4,6,7,9], k = 3, x = 6. We would remove 1 and then remove 9. What remains
 is the result. I use two pointers method to remove the element. One pointer
  points to the front of the array and the other points to the back. The time complexity is O(n - k) because we remove (n-k) elements. Please see the code as follows:

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if (k >= arr.size()) return arr;
        int i = 0, j = arr.size() - 1;
        while (j - i + 1 > k) {
            if (x - arr[i] > arr[j] - x) i++;
            else j--;
        }
        return vector<int>(arr.begin() + i, arr.begin() + i + k);
    }
};

Explanation:
Assume we are taking A[i] ~ A[i + k -1].
We can binary research i
We compare the distance between x - A[mid] and A[mid - k] - x

If x - A[mid] > A[mid + k] - x,
it means A[mid + 1] ~ A[mid + k] is better than A[mid] ~ A[mid + k - 1],
and we have mid smaller than the right i.
So assign left = mid + 1.

Note that, you shouldn't compare the absolute value abs(x - A[mid]) and abs(A[mid + k] - x).
It's wrong though it get accepetd.
It fails at the case A = [1,1,2,2,2,2,2,3,3], x=3, k=2

vector<int> findClosestElements(vector<int>& A, int k, int x) {
        int left = 0, right = A.size() - k;
        while (left < right) {
            int mid = (left + right) / 2;
            if (x - A[mid] > A[mid + k] - x)
                left = mid + 1;
            else
                right = mid;
        }
        return vector<int>(A.begin() + left, A.begin() + left + k);
 }

[LeetCode] Number of Longest Increasing Subsequence 最长递增序列的个数
 

Given an unsorted array of integers, find the number of longest increasing subsequence.

Example 1:

Input: [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int res = 0, mx = 0, n = nums.size();
        vector<int> len(n, 1), cnt(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] <= nums[j]) continue;
                if (len[i] == len[j] + 1) 
                	cnt[i] += cnt[j];
                else if (len[i] < len[j] + 1) {
                	len[i] = len[j] + 1;
                	cnt[i] = cnt[j];
                }
            }
            if (mx == len[i])
                res += cnt[i];
            else if (mx < len[i]) {
                mx = len[i];
                res = cnt[i];
            }
        }
        return res;
    }
};

/*Given a binary tree with n nodes, your task is to check if it's possible to partition 
the tree to two trees which have the equal sum of values after removing exactly one edge on the original tree.
*/

class Solution {
public:
    bool checkEqualTree(TreeNode* root) {
        unordered_map<int, int> m;
        int sum = helper(root, m);
        if (sum == 0) return m[0] > 1;
        return sum %2 == 0 && m.count(sum/2);
    }
    int helper(TreeNode* node, unordered_map<int, int>& m) {
        if (!node) return 0;
        int cur = node->val + helper(node->left, m) + helper(node->right, m);
        ++m[cur];
        return cur;
    }
};


Given a binary tree, find the length of the longest path where each node in the path has 
the same value. This path may or may not pass through the root.

Note: The length of path between two nodes is represented by the number of edges between them.

Example 1:

class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
    int helper(TreeNode* node, int& res) {
        if (!node) return 0;
        int left = helper(node->left, res);
        int right = helper(node->right, res);
        left = (node->left && node->val == node->left->val):left + 1:0;
        right = (node->right && node->val == node->right->val) ? right + 1 : 0;
        res = max(res, left + right);
        return max(left, right);
    }
};

Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

Example 1:

Input: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int res = 0;
        vector<int> start;
        helper(root, 0, 1, start, res);
        return res;
    }
    void helper(TreeNode* node, int h, int idx, vector<int>& start, int& res) {
        if (!node) return;
        if (h >= start.size()) 
        	start.push_back(idx);
        res = max(res, idx - start[h] + 1);
        helper(node->left, h + 1, idx * 2, start, res);
        helper(node->right, h + 1, idx * 2 + 1, start, res);
    }
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root, 1});
        while (!q.empty()) {
            int left = q.front().second, right = left, n = q.size();
            for (int i = 0; i < n; ++i) {
                auto t = q.front().first; 
                right = q.front().second; q.pop();
                if (t->left) q.push({t->left, right * 2});
                if (t->right) q.push({t->right, right * 2 + 1});
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};


[LeetCode] Largest Plus Sign 最大的加型符号
 

In a 2D grid from (0, 0) to (N-1, N-1), every cell contains a 1, except those cells in the given list mines which are 0. What is the largest axis-aligned plus sign of 1s contained in the grid? Return the order of the plus sign. If there is none, return 0.

An "axis-aligned plus sign of 1s of order k" has some center grid[x][y] = 1 along with 4 arms of length k-1going up, down, left, and right, and made of 1s. This is demonstrated in the diagrams below. Note that there could be 0s or 1s beyond the arms of the plus sign, only the relevant area of the plus sign is checked for 1s.


class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        int res = 0, cnt = 0;
        vector<vector<int>> dp(N, vector<int>(N, 0));
        unordered_set<int> s;
        for (auto mine : mines) s.insert(mine[0] * N + mine[1]);
        for (int j = 0; j < N; ++j) {
            cnt = 0;
            for (int i = 0; i < N; ++i) { // up
                cnt = s.count(i * N + j) ? 0 : cnt + 1;
                dp[i][j] = cnt;
            }
            cnt = 0;
            for (int i = N - 1; i >= 0; --i) { // down
                cnt = s.count(i * N + j) ? 0 : cnt + 1;
                dp[i][j] = min(dp[i][j], cnt);
            }
        }
        for (int i = 0; i < N; ++i) {
            cnt = 0;
            for (int j = 0; j < N; ++j) { // left
                cnt = s.count(i * N + j) ? 0 : cnt + 1;
                dp[i][j] = min(dp[i][j], cnt);
            }
            cnt = 0;
            for (int j = N - 1; j >= 0; --j) { // right
                cnt = s.count(i * N + j) ? 0 : cnt + 1;
                dp[i][j] = min(dp[i][j], cnt);
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};

 class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        int res = 0;
        vector<vector<int>> dp(N, vector<int>(N, N));
        for (auto mine : mines) 
        	dp[mine[0]][mine[1]] = 0;
        for (int i = 0; i < N; ++i) {
            int l = 0, r = 0, u = 0, d = 0;
            for (int j = 0, k = N - 1; j < N; ++j, --k) {
                dp[i][j] = min(dp[i][j], l = (dp[i][j] ? l + 1 : 0));
                dp[j][i] = min(dp[j][i], u = (dp[j][i] ? u + 1 : 0));
                dp[i][k] = min(dp[i][k], r = (dp[i][k] ? r + 1 : 0));
                dp[k][i] = min(dp[k][i], d = (dp[k][i] ? d + 1 : 0));
            }
        }
        for (int k = 0; k < N * N; ++k) res = max(res, dp[k / N][k % N]);
        return res;
    }
};
Given a list of unique words. Find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

Example 1:
Given words = ["bat", "tab", "cat"]
Return [[0, 1], [1, 0]]
The palindromes are ["battab", "tabbat"]

Example 2:
Given words = ["abcd", "dcba", "lls", "s", "sssll"]
Return [[0, 1], [1, 0], [3, 2], [2, 4]]
The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        unordered_map<string, int> m;
        set<int> s;
        for (int i = 0; i < words.size(); ++i) {
            m[words[i]] = i;
            s.insert(words[i].size());
        }
        for (int i = 0; i < words.size(); ++i) {
            string t = words[i];
            int len = t.size();
            reverse(t.begin(), t.end());
            if (m.count(t) && m[t] != i) {
                res.push_back({i, m[t]});
            }
            auto a = s.find(len);
            for (auto it = s.begin(); it != a; ++it) {
                int d = *it;
                if (isValid(t, 0, len - d - 1) && m.count(t.substr(len - d))) {
                    res.push_back({i, m[t.substr(len - d)]});
                }
                if (isValid(t, d, len - 1) && m.count(t.substr(0, d))) {
                    res.push_back({m[t.substr(0, d)], i});
                }
            }
        }
        return res;
    }
    bool isValid(string t, int left, int right) {
        while (left < right) {
            if (t[left++] != t[right--]) return false;
        }
        return true;
    }
};

/*
Given a robot cleaner in a room modeled as a grid.

Each cell in the grid can be empty or blocked.

The robot cleaner with 4 given APIs can move forward, turn left or turn right. Each turn it made is 90 degrees.

When it tries to move into a blocked cell, its bumper sensor detects the obstacle and it stays on the current cell.

Design an algorithm to clean the entire room using only the 4 given APIs shown below.

interface Robot {
  // returns true if next cell is open and robot moves into the cell.
  // returns false if next cell is obstacle and robot stays on the current cell.
  boolean move();

  // Robot will stay on the same cell after calling turnLeft/turnRight.
  // Each turn will be 90 degrees.
  void turnLeft();
  void turnRight();

  // Clean the current cell.
  void clean();
}
*/

class Solution {
public:
    vector<vector<int>> dirs{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    void cleanRoom(Robot& robot) {
        unordered_set<string> visited;
        helper(robot, 0, 0, 0, visited);
    }
    void helper(Robot& robot, int x, int y, int dir, unordered_set<string>& visited) {
        robot.clean();
        visited.insert(to_string(x) + "-" + to_string(y));
        for (int i = 0; i < 4; ++i) {
            int cur = (i + dir) % 4, newX = x + dirs[cur][0], newY = y + dirs[cur][1];
            if (!visited.count(to_string(newX) + "-" + to_string(newY)) && robot.move()) {
                helper(robot, newX, newY, cur, visited);
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnLeft();
                robot.turnLeft();
            }
            robot.turnRight();
        }
    }
};

Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

 

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root) helper(root, "", res);
        return res;
    }
    void helper(TreeNode* node, string out, vector<string>& res) {
        if (!node->left && !node->right) 
        	res.push_back(out + to_string(node->val));
        if (node->left)
        	 helper(node->left, out + to_string(node->val) + "->", res);
        if (node->right) 
        	helper(node->right, out + to_string(node->val) + "->", res);
    }
};

Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int m1 = INT_MAX, m2 = INT_MAX;
        for (auto a : nums) {
            if (m1 >= a) m1 = a;
            else if (m2 >= a) m2 = a;
            else return true;
        }
        return false;
    }
};


