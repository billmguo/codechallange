unival
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int res = 0;
        if (root) helper(root, root->val, res);
        return res;
    }
    int helper(TreeNode* node, int parent, int& res) {
        if (!node) return 0;
        int left = helper(node->left, node->val, res);
        int right = helper(node->right, node->val, res);
        res = max(res, left + right);
        if (node->val == parent) return max(left, right) + 1;
        return 0;
    }
};

class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if (!root) return 0;
        int res = helper(root,1) + helper(root, -1) + 1;
        return max(res, max(longestConsecutive(root->left), longestConsecutive(root->right)));
    }
    int helper(TreeNode* node, int diff) {
        if (!node) return 0;
        int left = 0, right = 0;
        if (node->left && node->val - node->left->val == diff)
          left = 1 + helper(node->left, diff);
        if (node ->right && node->val - node->right->val == diff)
          right = 1 + helper(node->right, diff);
        return max(left,right);
    }
};
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        int res = 0;
        helper(root, root, res);
        return res;
    }
    pair<int, int> helper(TreeNode* node, TreeNode* parent, int& res) {
        if (!node) return {0, 0};
        auto left = helper(node->left, node, res);
        auto right = helper(node->right, node, res);
        res = max(res, left.first + right.second + 1);
        res = max(res, left.second + right.first + 1);
        int inc = 0, dec = 0;
        if (node->val > parent->val ) {
            inc = max(left.first, right.first) + 1;
        } else if (node->val < parent->val) {
            dec = max(left.second, right.second) + 1;
        }
        return {inc, dec};
    }
};
