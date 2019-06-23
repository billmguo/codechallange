Given a binary tree rooted at root, the depth of each node is the shortest distance to the root.

A node is deepest if it has the largest depth possible among any node in the entire tree.

The subtree of a node is that node, plus the set of all descendants of that node.

Return the node with the largest depth such that it contains all the deepest nodes in its subtree.


class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return deep(root).second;
    }
    pair<int, TreeNode*> deep(TreeNode* root) {
        if (!root) return {0, NULL};
        pair<int, TreeNode*> l = deep(root->left), r = deep(root->right);
        int d1 = l.first, d2 = r.first;
        return {max(d1,d2) + 1, d1==d2? root: d1 > d2?l.second:r.second};
    }
};



On a 2 dimensional grid with R rows and C columns, we start at (r0, c0) facing east.

Here, the north-west corner of the grid is at the first row and column, and the south-east corner of the grid is at the last row and column.

Now, we walk in a clockwise spiral shape to visit every position in this grid. 

Whenever we would move outside the boundary of the grid, we continue our walk outside the grid (but may return to the grid boundary later.) 

Eventually, we reach all R * C spaces of the grid.

Return a list of coordinates representing the positions of the grid in the order they were visited.

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int>> res{{r0, c0}};
        vector<int> dirX{0, 1, 0, -1}, dirY{1, 0, -1, 0};
        int step = 0, cur = 0;
        while (res.size() < R * C) {
            if (cur == 0 || cur == 2) ++step;
            for (int i = 0; i < step; i++) {
                r0 += dirX[cur]; c0 += dirY[cur];
                if (r0 >= 0 && r0 < R && c0 >= 0 && c0 < C) res.push_back({r0,c0});
            }
            cur = (cur + 1)%4;
        }
        return res;
    }
};

Given a string S of '(' and ')' parentheses, we add the minimum number of parentheses ( '(' or ')', and in any positions ) so that the resulting parentheses string is valid.

Formally, a parentheses string is valid if and only if:

It is the empty string, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
Given a parentheses string, return the minimum number of parentheses we must add to make the resulting string valid

class Solution {
public:
    int minAddToMakeValid(string S) {
        int left = 0, right = 0;
        for(auto a:S) {
            if (a == '(')
                left++;
            else if (left > 0)
                left--;
            else
                right++;
        }
        return left + right;
    }
};

Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.

Here, a circular array means the end of the array connects to the beginning of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)

Also, a subarray may only include each element of the fixed buffer A at most once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)



class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int total = 0, maxsum = -30000, curmax = 0, minsum = 30000, curmin = 0;
        for (int a : A) {
            curmax = max(curmax + a, a);
            maxsum = max(maxsum, curmax);
            curmin = min(curmin + a, a);
            minsum = min(minsum, curmin);
            total += a;
        }
        return maxsum > 0 ? max(maxsum, total - minsum) : maxsum;
    }
};

An array is monotonic if it is either monotone increasing or monotone decreasing.

An array A is monotone increasing if for all i <= j, A[i] <= A[j].  An array A is monotone decreasing if for all i <= j, A[i] >= A[j].

Return true if and only if the given array A is monotonic.


class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if (A.size() <= 2)
            return true;
        bool inc = true, dec = true;
        for(int i = 1; i < A.size() ; i++) {
            inc &= A[i] >= A[i-1];
            dec &= A[i] <= A[i-1];        
        }
        return inc||dec;
    }
};
