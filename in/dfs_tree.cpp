Given the root node of a binary search tree (BST) and a value to be inserted into the tree,
 insert the value into the BST. Return the root node of the BST after the insertion. 
 It is guaranteed that the new value does not exist in the original BST.

Note that there may exist multiple valid ways for the insertion, as long as the tree
 remains a BST after insertion. You can return any of them.



class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root)
            return new TreeNode(val);
        if (root->val > val)
            root->left = insertIntoBST(root->left, val);
        else
            root->right = insertIntoBST(root->right, val);
        return root;
    }
};

/*
[LeetCode] Second Minimum Node In a Binary Tree 二叉树中第二小的结点
 

Given a non-empty special binary tree consisting of nodes with the non-negative value, 
where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes,
 then this node's value is the smaller value among its two sub-nodes.*/

class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        int first = root->val, second = INT_MAX;
        helper(root, first, second);
        return (second == first || second == INT_MAX) ? -1 : second;
    }
    void helper(TreeNode* node, int& first, int& second) {
        if (!node) return;
        if (node->val != first && node->val < second) {
            second = node->val;
        }
        helper(node->left, first, second);
        helper(node->right, first, second);
    }
};



class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int unweighted = 0, weighted = 0;
        queue<vector<NestedInteger>> q;
        q.push(nestedList);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                vector<NestedInteger> t = q.front(); q.pop();
                for (auto a : t) {
                    if (a.isInteger()) unweighted += a.getInteger();
                    else if (!a.getList().empty()) q.push(a.getList());
                }
            }
            weighted += unweighted;
        }
        return weighted;
    }
};


Count the corner rectangele

class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = i + 1; j < m; ++j) {
                int cnt = 0;
                for (int k = 0; k < n; ++k) {
                    if (grid[i][k] == 1 && grid[j][k] == 1) ++cnt;
                }
                res += cnt * (cnt - 1) / 2;
            }
        }
        return res;
    }
};

factorial decompose

class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        vector<int> out;
        helper(n, 2, out, res);
        return res;
    }
    void helper(int n, int start, vector<int> out, vector<vector<int>> &res) {
        if (n == 1) {
            if (out.size() > 1) res.push_back(out);
        } else {
            for (int i = start; i <= n; ++i) {
                if (n % i == 0) {
                    out.push_back(i);
                    helper(n / i, i, out, res);
                    out.pop_back();
                }
            }
        }
    }
};





vector<string> solve(string &in, int k) {
    vector<string> res;
    unordered_set<string> m;
    for (int i = 0; i < in.size() - k; i++) {
        string sub = in.substr(i, k);
        if (m.count(sub)){
            res.push_back(sub);
        }
        m.insert(sub);
    }
    return res;
}



class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > res;
        vector<int> out;
        dfs(k, n, 1, out, res);
        return res;
    }
    void dfs(int k, int n, int level, vector<int> &out, vector<vector<int> > &res) {
        if (n < 0) return;
        if (n == 0 && out.size() == k) res.push_back(out);
        for (int i = level; i <= 9; ++i) {
            out.push_back(i);
            dfs(k, n - i, i + 1, out, res);
            out.pop_back();
        }
    }
};


void dfs(int remain, int maxval,  vector<int> &out, vector<vector<int>> &res) {
    if (remain == 0) {
        res.push_back(out);
        return;
    }
    for (int i = maxval; i >= 1; i--) {
        if (i > remain)
            continue;
        out.push_back(i);
        dfs(remain - i, i, out, res);
        out.pop_back();
    }
}
