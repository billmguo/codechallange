Given a binary tree, return the vertical order traversal of its nodes
 values. (ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be 
from left to right.

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        map<int, vector<int>> m;
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        while (!q.empty()) {
            auto a = q.front(); q.pop();
            m[a.first].push_back(a.second->val);
            if (a.second->left) q.push({a.first - 1, a.second->left});
            if (a.second->right) q.push({a.first + 1, a.second->right});
        }
        for (auto a : m) {
            res.push_back(a.second);
        }
        return res;
    }
};

A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid + 1]) left = mid + 1;
            else right = mid;
        }
        return right;
    }
};

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) return i - 1;
        }
        return nums.size() - 1;
    }
};

print rob path

int rob(vector<int> &num) {
        if (num.size() <= 1) return num.empty() ? 0 : num[0];
        int n = num.size();
        vector<int> dp(n, 0);
        dp[0] = num[0];
        vector<int> path(n, -2);
        if (num[0] > num[1]) {
            dp[1] = max(num[0], num[1]);
            path[1] = 0;
        } 
        
        vector<int> res;
        for (int i = 2; i < num.size(); ++i) {
            if (num[i] + dp[i - 2] >= dp[i - 1]) {
                path[i] = i - 2;
                dp[i] = num[i] + dp[i - 2];
            } else {
                path[i] = i - 1 ;
                dp[i] = dp[i - 1];
            }
        }
        int i = n - 1;
        while (i >= 0) {
            cout<< num[i]<<path[i]<<i<<endl;
            if (path[i] == i - 1) {
                i--;
            } else {
                res.insert(res.begin(), num[i]);
                i = path[i];
            }
        }
        return dp.back();
    }
