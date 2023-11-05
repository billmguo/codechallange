/*Given an unsorted array of integers, find the length of the longest consecutive elements sequence.*/

Your algorithm should run in O( n ) complexity.
class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    int ans = 0;
    unordered_set<int> seen{nums.begin(), nums.end()};

    for (int num : nums) {
      // Num is the start of a sequence
      if (seen.count(num - 1))
        continue;
      int length = 1;
      while (seen.count(++num))
        ++length;
      ans = max(ans, length);
    }

    return ans;
  }
};



/*Description
There are n soldiers standing in a line. Each soldier is assigned a unique rating value.

You have to form a team of 3 soldiers amongst them under the following rules:

Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).

Example 1:

Input: rating = [2,5,3,4,1]

Output: 3

Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1).


The object of this problem is to find the number of monotone subsequences that have length 3 of the given array rating.
 Since the length of rating does not exceed 200, this problem can be solved by brute force. A solution of dynamic
  programming also exists.

Consider two cases, where each subsequence is monotonically increasing or monotonically decreasing. 
First consider the monotonically increasing case. Create an array dp of length n, wnere dp[i] represents 
the number of elements in subarray rating[0..i - 1] that are less than rating[i]. Loop over i from 1 to n - 1. For each i,
 loop over j from i - 1 to 0. If rating[i] > rating[j], then increase dp[i] by 1, and at the same time, if dp[j] > 0,
  then there exist several elements before j that are less than rating[j], so add dp[j] to the number of teams. After the loop, 
  the number of teams that are monotically increasing can be obtained.

For the monotonically decrease case, the logic is almost the same except that rating[i] < rating[j]
 is used instead of rating[i] > rating[j].
*/



class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size(), ans = 0;
        for (int j = 1; j < n - 1; ++j) {
            int ia = 0, ib = 0, ka = 0, kb = 0;
            for (int i = 0; i < j; ++i) {
                if (rating[i] < rating[j])
                    ++ia;
                else if (rating[i] > rating[j])
                    ++ib;
            }
            for (int k = j + 1; k < n; ++k) {
                if (rating[j] < rating[k])
                    ++ka;
                else if (rating[j] > rating[k])
                    ++kb;
            }
            ans += ia * ka + ib * kb;
        }
        return ans;
    }
};


809. Expressive Words

Sometimes people repeat letters to represent extra feeling, such as “hello” -> “heeellooo”, “hi” -> “hiiii”.  Here, we have groups, of adjacent letters that are all the same character, and adjacent characters to the group are different.  A group is extended if that group is length 3 or more, so “e” and “o” would be extended in the first example, and “i” would be extended in the second example.  As another example, the groups of “abbcccaaaa” would be “a”, “bb”, “ccc”, and “aaaa”; and “ccc” and “aaaa” are the extended groups of that string.

class Solution {
 public:
  int expressiveWords(string s, vector<string>& words) {
    int ans = 0;

    for (const string& word : words)
      if (isStretchy(s, word))
        ++ans;

    return ans;
  }

 private:
  bool isStretchy(const string& s, const string& word) {
    const int n = s.length();
    const int m = word.length();

    int j = 0;
    for (int i = 0; i < n; ++i)
      if (j < m && s[i] == word[j])
        ++j;
      else if (i > 1 && s[i] == s[i - 1] && s[i - 1] == s[i - 2])
        continue;
      else if (i > 0 && i + 1 < n && s[i - 1] == s[i] && s[i] == s[i + 1])
        continue;
      else
        return false;

    return j == m;
  }
};
 


742 Given a binary tree where every node has a unique value, and a target key k, find the value of the nearest leaf node to target k in the tree.

Here,  nearest  to a leaf means the least number of edges travelled on the binary tree to reach any leaf of the tree. Also, a node is called a  leaf  if it has no children.

In the following examples, the input tree is represented in flattened form row by row. The actual root tree given will be a TreeNode object.

class Solution {
public:
    int findClosestLeaf(TreeNode* root, int k) {
        unordered_map<TreeNode*, TreeNode*> back;
        TreeNode *kNode = find(root, k, back);
        queue<TreeNode*> q{{kNode}};
        unordered_set<TreeNode*> visited{{kNode}};
        while (!q.empty()) {
            TreeNode *t = q.front(); q.pop();
            if (!t->left && !t->right) return t->val;
            if (t->left && !visited.count(t->left)) {
                visited.insert(t->left);
                q.push(t->left);
            }
            if (t->right && !visited.count(t->right)) {
                visited.insert(t->right);
                q.push(t->right);
            }
            if (back.count(t) && !visited.count(back[t])) {
                visited.insert(back[t]);
                q.push(back[t]);
            }
        }
        return -1;
    }
    TreeNode* find(TreeNode* node, int k, unordered_map<TreeNode*, TreeNode*>& back) {
        if (node->val == k) return node;
        if (node->left) {
            back[node->left] = node;
            TreeNode *left = find(node->left, k, back);
            if (left) return left;
        }
        if (node->right) {
            back[node->right] = node;
            TreeNode *right = find(node->right, k, back);
            if (right) return right;
        }
        return NULL;
    }
};


714. Best Time to Buy and Sell Stock with Transaction Fee

sold[i] = max(sold[i - 1], hold[i - 1] + prices[i] - fee);

hold[i] = max(hold[i - 1], sold[i - 1] - prices[i]);


class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<int> sold(prices.size(), 0), hold = sold;
        hold[0] = -prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            sold[i] = max(sold[i - 1], hold[i - 1] + prices[i] - fee);
            hold[i] = max(hold[i - 1], sold[i - 1] - prices[i]);
        }
        return sold.back();
    }
};

1299. Replace Elements with Greatest Element on Right Side

Companies
Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.

After doing so, return the array.

Example 1:

Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]


 vector<int> replaceElements(vector<int>& A) {
 	int mx = -1;
    for (int i = A.size() - 1; i >= 0; --i){
    		exchange(A[i], mx);
            mx = max(mx, A[i]);
        	
     }
     return A;
 }


 Input: nums = [2,4,5,5,5,5,5,6,6], target = 5
Output: true
Explanation: 
The value 5 appears 5 times and the length of the array is 9.
Thus, 5 is a majority element because 5 > 9/2 is true.


class Solution {
public:
    bool isMajorityElement(vector<int>& A, int target) {
    	int len = upper_bound(begin(A), end(A), target) - lower_bound(begin(A), end(A), target);
    	return len > A.size()/2;
    }
};


class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int k) {
        sort(begin(A), end(A));
        int i = 0, j = A.size() - 1, ans = INT_MIN;
        while (i < j) {
            int sum = A[i] + A[j];
            if (sum < k) {
                ans = max(ans, sum);
                ++i;
            } else --j;
        }
        return ans == INT_MIN ? -1 : ans;
    }
};



993. Cousins in Binary Tree


In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are  cousins  if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

while(!q.empty()) {
	for (int n = q.size(); i >= 0; i--)
}

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q{{root}};
        bool isX = false, isY = false;
        while (!q.empty()) {
        	int n = q.size();
            for (int i =0; i < n;i++) {
                TreeNode *cur = q.front(); q.pop();
                if (cur->val == x) isX = true;
                if (cur->val == y) isY = true;

                if (cur->left && cur->right) {
                    int left = cur->left->val, right = cur->right->val;
                    if ((left == x && right == y) || (left == y && right == x)) 
                    	return false;
                }
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            if (isX && isY) return true;
            if (isX || isY) return false;
        }
        return false;
    }
};

989. Add to Array-Form of Integer

For a non-negative integer X, the  array-form ofX  is an array of its digits in left to right order.  For example, if X = 1231, then the array form is [1,2,3,1].

Given the array-form A of a non-negative integer X, return the array-form of the integer X+K.


class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> res;
        for (int i = (int)A.size() - 1; i >= 0; --i) {
            res.insert(res.begin(), (A[i] + K) % 10);
            K = (A[i] + K) / 10;
        }
        while (K > 0) {
            res.insert(res.begin(), K % 10);
            K /= 10;
        }
        return res;
    }
};

Given an array A of integers, return the number of (contiguous, non-empty) subarrays that have a sum divisible by K.

Example 1:

Input: A = [4,5,0,-2,-3,1], K = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by K = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int res = 0, sum = 0;
        vector<int> cnt(K);
        cnt[0] = 1;


        for (int num : A) {
            sum = (sum + num % K + K) % K;
            res += cnt[sum];
            ++cnt[sum];
        }
        return res;
    }
};
897. Increasing Order Search Tree


Given a tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree,

 and every node has no left child and only 1 right child. ``` Example 1: Input: [5,3,6,2,4,null,8,1,null,null,null,7,9]


class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        return helper(root, nullptr);
    }
    TreeNode* helper(TreeNode* node, TreeNode* pre) {
        if (!node) 
        	return pre;
        TreeNode* res = helper(node->left, node);
        node->left = nullptr;
        node->right = helper(node->right, pre);
        return res;
    }
};

814. Binary Tree Pruning
We are given the head node root of a binary tree, where additionally every node’s value is either a 0 or a 1.

Return the same tree where every subtree (of the given tree) not containing a 1 has been removed.

(Recall that the subtree of a node X is X, plus every node that is a descendant of X.)


Example 1:
Input: [1,null,0,0,1]
Output: [1,null,0,null,1]
 
Explanation: 
Only the red nodes satisfy the property "every subtree not containing a 1".
The diagram on the right represents the answer.


class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (!root) return NULL;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if (!root->left && !root->right && root->val == 0)
        	return nullptr;
        else
        	return root;
    }
};

437. Path Sum III

You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.



class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> m;
        m[0] = 1;
        return helper(root, sum, 0, m);
    }
    int helper(TreeNode* node, int sum, int cursum, unordered_map<int, int>& m) {
        if (!node) return 0;
        cursum  += node->val;
        int res = m[cursum - sum];
        ++m[cursum];
        res += helper(node->left, sum, cursum, m) + helper(node->right, sum, cursum, m);
        --m[cursum];
        return res;
    }


};

870. Advantage Shuffle



Given two arrays A and B of equal size, the advantage of A with respect to B is the number of indices i 
for which A[i] > B[i].

Return any permutation of A that maximizes its advantage with respect to B.

for which A[i] > B[i].

	Example 1:

Input: A = [2,7,11,15], B = [1,10,4,11]
Output: [2,11,7,15]


class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int n = A.size(), left = 0, right = n - 1;
        vector<int> res(n);
        sort(A.begin(), A.end());
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i)
        	 q.push({B[i], i});
        while (!q.empty()) {
        	auto [val,idx] = q.top();
        	q.pop();
        	if (A[right] > val)
        		res[idx] = A[right--];
        	else
        		res[idx] = A[left++];
          
        }
        return res;
    }
};

735. Asteroid Collision

We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction
 (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one
 will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.


 class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for (int i = 0; i < asteroids.size(); ++i) {
            if (asteroids[i] > 0) {
                res.push_back(asteroids[i]);
            } else if (res.empty() || res.back() < 0) {
                res.push_back(asteroids[i]);
            } else if (res.back() <= -asteroids[i]) {
                if (res.back() < -asteroids[i]) --i;
                res.pop_back();
            }
        }
        return res;
    }
};

402. Remove K Digits

Given a non-negative integer  num  represented as a string, remove 
 k  digits from the number so that the new number is the smallest possible.

Note:

The length of  num  is less than 10002 and will be ≥  k.
The given  num  does not contain any leading zero


class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";

        int n = num.size(), keep = n - k;

        for (char c:num) {
        	while (k && !res.empty() && res.back() > c) {
        		res.pop_back();
        		--k;
        	}
        	res.push_back(c);
        }
        res.resize(keep);
        while (!res.empty() && res[0] =='0')
        	res.erase(res.bgin());
       
        return res.empty() ? "0" : res;
    }
};


378. Kth Smallest Element in a Sorted Matrix

Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> q;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                q.emplace(matrix[i][j]);
                if (q.size() > k) q.pop();
            }
        }
        return q.top();
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = matrix[0][0], right = matrix.back().back();
        while (left < right) {
            int mid = left + (right - left) / 2, cnt = 0;
            for (int i = 0; i < matrix.size(); ++i) {
                cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if (cnt < k) 
            	left = mid + 1;
            else 
            	right = mid;
        }
        return left;
    }
};


377. Combination Sum IV
Given an integer array with all positive numbers and no duplicates, find the number of possible
 combinations that add up to a positive integer target.

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (auto a : nums) {
                if (i >= a) dp[i] += dp[i - a];
            }
        }
        return dp.back();
    }
};

42. Trapping Rain Water
Given  n  non-negative integers representing an elevation map
 where the width of each bar is 1, compute how much water it is able to trap after raining.

class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0, mx = 0, n = height.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            dp[i] = mx;
            mx = max(mx, height[i]);
        }
        mx = 0;
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = min(dp[i], mx);
            mx = max(mx, height[i]);
            if (dp[i] > height[i]) res += dp[i] - height[i];
        }
        return res;
    }
};


We are given head, the head node of a linked list containing unique integer values.

We are also given the list G, a subset of the values in the linked list.

Return the number of connected components in G, where two values are connected 
if they appear consecutively in the linked list.

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        int res = 0;
        unordered_set<int> m(G.begin(), G.end());
        while (head) {
            if (m.count(head->val) && (!head->next || !m.count(head->next->val))) {
                ++res;
            }
            head = head->next;
        }
        return res;
    }
};

1019. Next Greater Node In Linked List

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res, nums;
        stack<int> st;
        int cnt = 0;
        while (head) {
            nums.push_back(head->val);
            while (!st.empty() && head->val > nums[st.top()]) {
                res[st.top()] = head->val;
                st.pop();
            }
            st.push(cnt);
            res.resize(++cnt);
            head = head->next;
        }
        return res;
    }
};
