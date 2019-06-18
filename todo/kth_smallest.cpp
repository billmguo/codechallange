class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        stack<TreeNode*> st;
        TreeNode *p = root;
        while(p || !st.empty()) {
            while(p) {
                st.push_back(p);
                p = p->left;
            }
            p = st.top();
            st.pop();
            ++cnt;
            if (cnt == k)
                return p->val;
            p = p ->right;
        }
        return 0;
    }
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        return kthSmallestDFS(root, k);
    }
    int kthSmallestDFS(TreeNode* root, int &k) {
        if (!root)
            return -1;
        int left = kthSmallestDFS(root->left, k);
        if (k == 0) return left;
        if (--k == 0) return root->val;
        int right = kthSmallestDFS(root->right, k);
        return right;
    }
};
