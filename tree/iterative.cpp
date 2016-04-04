l.



postorder postorderTraversal



/**

 * Definition for binary tree

 * struct TreeNode {

 *     int val;

 *     TreeNode *left;

 *     TreeNode *right;

 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}

 * };

 */

class Solution {

public:

    vector<int> postorderTraversal(TreeNode *root) {

        vector<int> res;

        if (!root) return res;

        stack<TreeNode*> s;

        s.push(root);

        TreeNode *head = root;

        while (!s.empty()) {

            TreeNode *top = s.top();

            if ((!top->left && !top->right) || top->left == head || top->right == head) {

                res.push_back(top->val);

                s.pop();

                head = top;

            } else {

                if (top->right) s.push(top->right);

                if (top->left) s.push(top->left);

            }

        }

        return res;

    }

};



preorderTraversal



/**

 * Definition for binary tree

 * struct TreeNode {

 *     int val;

 *     TreeNode *left;

 *     TreeNode *right;

 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}

 * };

 */

class Solution {

public:

    vector<int> preorderTraversal(TreeNode *root) {

        vector<int> res;

        stack<TreeNode*> s;

        if (!root) return res;

        s.push(root);

        while (!s.empty()) {

            TreeNode *p = s.top();

            res.push_back(p->val);

            s.pop();

            if (p->right) s.push(p->right);

            if (p->left) s.push(p->left);

        }

        return res;

    }

};



/*inorder trasverse*/



// Recursion

class Solution {

public:

    vector<int> inorderTraversal(TreeNode *root) {

        vector<int> res;

        inorder(root, res);

        return res;

    }

    void inorder(TreeNode *root, vector<int> &res) {

        if (!root) return;

        if (root->left) inorder(root->left, res);

        res.push_back(root->val);

        if (root->right) inorder(root->right, res);

    }

};



// Non-recursion

class Solution {

public:

    vector<int> inorderTraversal(TreeNode *root) {

        vector<int> res;

        stack<TreeNode*> s;

        TreeNode *p = root;

        while (p || !s.empty()) {

            while (p) {

                s.push(p);

                p = p->left;

            }

            p = s.top();

            s.pop();

            res.push_back(p->val);

            p = p->right;

        }

        return res;

    }

};





// Non-recursion and no stack

class Solution {

public:

    vector<int> inorderTraversal(TreeNode *root) {

        vector<int> res;

        if (!root) return res;

        TreeNode *cur, *pre;

        cur = root;

        while (cur) {

            if (!cur->left) {

                res.push_back(cur->val);

                cur = cur->right;

            } else {

                pre = cur->left;

                while (pre->right && pre->right != cur) pre = pre->right;

                if (!pre->right) {

                    pre->right = cur;

                    cur = cur->left;

                } else {

                    pre->right = NULL;

                    res.push_back(cur->val);

                    cur = cur->right;

                }

            }

        }

        return res;

    }

};

