Given an integer array A, you partition the array into (contiguous) 
subarrays of length at most K.  After partitioning, each subarray has 
their values changed to become the maximum value of that subarray.
Return the largest sum of the given array after partitioning.

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int n = A.size();
        vector<int> dp(n + 1, 0);
        for(int i=1; i <= n; i++) {
            int curm=0;
            for(int j = i-1; j >= 0 &&j >= i-K ; j--) {
                curm = max(curm, A[j]);
                dp[i] = max(dp[i], dp[j] + curm * (i - j));
            }
        }
        return dp.back();
    }
};

Given an array A of integers, return the length of the longest arithmetic 
subsequence in A.

Recall that a subsequence of A is a list A[i_1], A[i_2], ..., A[i_k] with 
0 <= i_1 < i_2 < ... < i_k <= A.length - 1, and that a sequence B is arithmetic 
if B[i+1] - B[i] are all the same value (for 0 <= i < B.length - 1).

 

Example 1:

Input: [3,6,9,12]
Output: 4
Explanation: 
The whole array is an arithmetic sequence with steps of length = 3.


class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        unordered_map<int, unordered_map<int, int>> dp;
        int res = 2;
        for (int i = 1; i < A.size(); i++) {
            for (int j = 0; j < i; j++) {
                int a = A[i], b = A[j];
                dp[a-b][i] = dp[a-b].count(j)? dp[a-b][j] + 1:2;
                res = max(res, dp[a-b][i]);
            }
        }
        return res;
    }
};



Given an array A of 0s and 1s, we may change up to K values from 0 to 1.
Return the length of the longest (contiguous) subarray that contains only 1s. 

 

Example 1:

Input: A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
Output: 6
Explanation: 
[1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int i = 0, len = 0, cnt[2] ={};
        for (int j = 0; j < A.size();j++) {
            cnt[A[j]]++;
            while (cnt[0] > K)
                cnt[A[i++]]--;
            len = max(len, j - i + 1);
        }
        return len;
    }
};


We are given the root node of a maximum tree: a tree where every
 node has a value greater than any other value in its subtree.

Just as in the previous problem, the given tree was constructed from an list A 
(root = Construct(A)) recursively with the following Construct(A) routine:

If A is empty, return null.
Otherwise, let A[i] be the largest element of A.  Create a root node with value A[i].
The left child of root will be Construct([A[0], A[1], ..., A[i-1]])
The right child of root will be Construct([A[i+1], A[i+2], ..., A[A.length - 1]])
Return root.
Note that we were not given A directly, only a root node root = Construct(A).

Suppose B is a copy of A with the value val appended to it.  It is guaranteed that B has unique values.

Return Construct(B).

class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if (root && root->val > val) {
            root->right = insertIntoMaxTree(root->right, val);
            return root;
        }
        TreeNode *node = new TreeNode(val);
        node->left = root;
        return node;      
    }
};

TreeNode *insert(TreeNode *root, int val) {
	if (root && root->val > val) {
		root->right = insert(root->right,val);
		return root;
	}
	TreeNode *node = new TreeNode(val);
	node->left = root;
	return node;
}

For a non-negative integer X, the array-form of X is an array of its 
digits in left to right order.  For example, if X = 1231, then the array 
form is [1,2,3,1].

Given the array-form A of a non-negative integer X, return the
 array-form of the integer X+K.


class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        for (int i = A.size() - 1; i >= 0 && K > 0; --i) {
            A[i] += K;
            K = A[i]/10;
            A[i]%=10;
        }
        while (K > 0) {
            A.insert(A.begin(),K%10);
            K /= 10;
        }
        return A;
    }
};
