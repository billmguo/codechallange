class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (root == NULL)
            return 0;
        if (root->val < L)
            return rangeSumBST(root->right, L,R);
        if (root->val > R)
            return rangeSumBST(root->left, L, R);
        return root->val + rangeSumBST(root->right, L, R) + rangeSumBST(root->left, L, R);      
    }
};

int rangeSumBST(TreeNode* root, int L, int R) 
{
    if(root == nullptr)  return 0;
    int sum = 0;
    if(root->val <= R && root->val >= L)   sum = root->val;
    sum += rangeSumBST(root->left, L, R);
    sum += rangeSumBST(root->right, L, R);
    return sum;
}

class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int m = a.size() - 1, n = b.size() - 1, carry = 0;
        
        while (m >= 0 || n >= 0) {
          int p = m >= 0?a[m--] - '0': 0;
          int q = n >=0 ? b[n--] -'0':0;
          int sum = p + q + carry;
          res += to_string(sum%2) + res;
          carry = sum/2;
        }
        return carry == 1? "1" + res:res;
    }
};
