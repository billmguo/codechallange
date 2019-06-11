class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int res = root->val;
        while (root) {
            if (abs(res - target) >= abs(root->val - target)) {
                res = root->val;
            }
            root = target < root->val ? root->left : root->right;
        }
        return res;
    }
};


class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        inorder(root, target, k, res);
        return res;
    }
    void inorder(TreeNode *root, double target, int k, vector<int> &res) {
        if (!root) return;
        inorder(root->left, target, k, res);
        if (res.size() < k) res.push_back(root->val);
        else if (abs(root->val - target) < abs(res[0] - target)) {
            res.erase(res.begin());
            res.push_back(root->val);
        } else return;
        inorder(root->right, target, k, res);
    }
};


class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode *p = root;
        while (p || !s.empty()) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            p = s.top(); s.pop();
            if (res.size() < k) res.push_back(p->val);
            else if (abs(p->val - target) < abs(res[0] - target)) {
                res.erase(res.begin());
                res.push_back(p->val);
            } else break;
            p = p->right;
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        auto cmp = [](vector<int>& p, vector<int>& q) {
            return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        for (vector<int> &point:points) {
            pq.push(point);
            if (pq.size() > K)
                pq.pop();
        }
        vector<vector<int>> ans; 
        while(!pq.empty()) {
                ans.push_back(pq.top());
                pq.pop();
        }
        return ans;
    }
};
