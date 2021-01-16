Example:

Input: "4(2(3)(1))(6(5))"
Output: return the tree root node representing the following tree:

       4
     /   \
    2     6
   / \   / 
  3   1 5   


  TreeNode *string2tree(string &s) {
    if (s.empty())
      return nullptr;

    stack<TreeNode*> st;

    for (int i = 0; i < s.size(); i++) {
      int j = i;
      if (s[i] == ')')
        st.pop();
      else if (isidigit(s[i] || s[i] == '-')) {
        while (i + 1 < s.size() && isdigit[s[i + 1]])
          i++;
        TreeNode *node = new TreeNode(stoi(s.substr(j, i - j + 1)));
        if (!st.empty()) {
          if (st.top()->left != nullptr)
            st.top()->left = node;
          else
            st.top()->right = node;
        }
      }
    }

    return st.top();
  }

Return any binary tree that matches the given preorder and postorder traversals.

Values in the traversals pre and post are distinct positive integers.

 

Example 1:

Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        vector<TreeNode*> s;
        s.push_back(new TreeNode(pre[0]));
        for (int i = 1, j = 0; i < pre.size(); i++) {
            while (s.back()->val == post[j]) {
                s.pop_back();
                j++;
            }
            TreeNode *node = new TreeNode(pre[i]);
            if (s.back()->left == NULL)
                s.back()->left = node;
            else
                s.back()->right = node;
            s.push_back(node);
        }
        return s[0];
    }
};

The basic idea is to find the left subtree and the right subtree.

The root node must be the first element of the pre sequence.
The root node must be the last element of the post sequence.
The left subtree and the right subtree must be consecutive in both of the sequences.
pre: 1 | 2 4 5 | 3 6 7
post:  | 4 5 2 | 6 7 3 | 1
Start scanning from pre[1] and post[0]. Once they contains the same set of numbers, we can truncate it to be two parts. One is the left subtree, another is the right subtree.

class Solution {
public:
    TreeNode* constuctFromRange(vector<int>& pre, vector<int>& post, int s1, int e1, int s2, int e2) {
        if (s1 > e1 || s2 > e2) return NULL;
        TreeNode *root = new TreeNode(pre[s1]);
        if (s1 == e1) return root;
        int m1 = s1 + 1, m2 = s2;
        int set1 = 0, set2 = 0;
        while (set1 == 0 || set1 != set2) {
            set1 = set1 | (1 << pre[m1++]);
            set2 = set2 | (1 << post[m2++]);
        }
        root->left = constuctFromRange(pre, post, s1 + 1, m1 - 1, s2, m2 - 1);
        root->right = constuctFromRange(pre, post, m1, e1, m2, e2);
        return root;
    }
    
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return constuctFromRange(pre, post, 0, pre.size() - 1, 0, post.size() - 1);
    }
};


TreeNode *node = new TreeNode(pre[s[0]]);
vec.push_back(node);
for (int i = 1; i < pre.size(); i++) {
	TreeNode *node = new TreeNode(pre[i]);
	while(!vec.empty() and vec.back() == post[j]) {
		j++;
		vec.pop_back();
	}
	if (vec.back()->left == NULL)
		vec.back()->left = node;
	else
		vec.back()->right = node;
	vec.push_back(node);
}
return vec[0];


Return the length of the shortest, non-empty, contiguous subarray of A with sum at least K.

If there is no non-empty subarray with sum at least K, return -1.


class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int N = A.size(), res = N + 1;
        vector<int> B(N + 1, 0);
        for (int i = 0; i < N; i++) 
            B[i + 1] = B[i] + A[i];
        deque<int> d;
        for (int i = 0; i < N + 1; i++) {
            while (d.size() > 0 && B[i] - B[d.front()] >= K) {
                res = min(res, i - d.front());
                d.pop_front();
            }
            while (d.size() > 0 && B[i] <= B[d.back()])
                d.pop_back();
            d.push_back(i);
        }
        return res <= N ? res : -1; 
    }
};


class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>> > pq;
        int sum = 0;
        int ans = INT_MAX;
        for( int i = 0; i<A.size(); i++){
            sum += A[i];
            if( sum >= K ){
                ans = min(ans, i+1);
            }
            while( pq.size() && sum - pq.top().first >= K ){
                auto &p = pq.top();
                ans = min(ans, i-p.second);
                pq.pop();
            }
            pq.push({sum, i});
        }
        return ans == INT_MAX?-1:ans;
    }
};

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
