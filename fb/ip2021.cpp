Prepare_0217

[LeetCode] 1428. Leftmost Column with at Least a One
(This problem is an interactive problem.)

A binary matrix means that all elements are 0 or 1. For each individual row of the matrix, this row is sorted in non-decreasing order.

Given a row-sorted binary matrix binaryMatrix, return leftmost column index(0-indexed) with at least a 1 in it. If such index doesn't exist, return -1.

You can't access the Binary Matrix directly.  You may only access the matrix using a BinaryMatrix interface:

BinaryMatrix.get(row, col) returns the element of the matrix at index (row, col) (0-indexed).
BinaryMatrix.dimensions() returns a list of 2 elements [rows, cols], which means the matrix is rows * cols.

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface BinaryMatrix {
 *     public int get(int row, int col) {}
 *     public List<Integer> dimensions {}
 * };
 */

class Solution {
 public:
  int leftMostColumnWithOne(BinaryMatrix& binaryMatrix) {
    const vector<int> dimensions = binaryMatrix.dimensions();
    const int m = dimensions[0];
    const int n = dimensions[1];
    int ans = -1;
    int i = 0;
    int j = n - 1;

    while (i < m && j >= 0)
      if (binaryMatrix.get(i, j) == 1)
        ans = j--;
      else
        ++i;

    return ans;
  }
};


bool helper(BinaryMatrix &bm, int r, int c) {
    for (int r = 0; r < m; r++) {
            if (binaryMatrix.get(r, c) == 1) {
                return true;
            }
      }
        return false;
 }

int leftMostColumnWithOne(BinaryMatrix& bm){
	auto a = bm.dimensions();
	int m = a[0], n = a[1];
	int res = n;
	
	for (int i = 0; i < m ; i++) {
		int l = 0, r = n - 1;
		while (l < r) {
			int mid = l + (r - l)/2;
			if (bm.get(i, mid) == 0)
				l = mid + 1;
			else
				r = mid;
		}
		if (bm.get(i,l) == 1)
			res = min(res, l);
	}

	return res;
}


Maximum Difference Between Node and Ancestor

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        return helper(root, root->val, root->val);
    }
    int helper(TreeNode* node, int mn, int mx) {
        if (!node) return mx - mn;
        mn = min(mn, node->val);
        mx = max(mx, node->val);
        return max(helper(node->left, mn, mx), helper(node->right, mn, mx));
    }
};


two city scheudle 
class Solution {
public:
  int twoCitySchedCost(vector<vector<int>>& costs) {
    int n = costs.size();
    sort(begin(costs), end(costs), [](const auto& c1, const auto& c2){
      return c1[0] - c1[1] < c2[0] - c2[1];
    });
    int ans = 0;
    for (int i = 0; i < n; ++i)
      ans += i < n/2 ? costs[i][0] : costs[i][1];    
    return ans;
  }
};


Given a string S, count the number of distinct, non-empty subsequences of S .

Since the result may be large, return the answer modulo 10^9 + 7.

Example 1:

Input: "abc"
Output: 7
Explanation: The 7 distinct subsequences are "a", "b", "c", "ab", "ac", "bc", and "abc".

class Solution {
public:
  int distinctSubseqII(string S) {
    constexpr int kMod = 1e9 + 7;
    std::vector<int> counts(26);
    for (char c : S)
      counts[c - 'a'] = accumulate(begin(counts), end(counts), 1L) % kMod;
    return accumulate(begin(counts), end(counts), 0L) % kMod;
  }
};

Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down.
 You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

class Solution {
public:
    vector<vector<int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int res = 1, m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res = max(res, dfs(matrix, dp, i, j));
            }
        }
        return res;
    }


    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j) {
        if (dp[i][j]) return dp[i][j];
        int mx = 1, m = matrix.size(), n = matrix[0].size();
        for (auto a : dirs) {
            int x = i + a[0], y = j + a[1];
            if (x < 0 || x >= m || y < 0 |a| y >= n || matrix[x][y] <= matrix[i][j]) continue;
            int len = 1 + dfs(matrix, dp, x, y);
            mx = max(mx, len);
        }
        dp[i][j] = mx;
        return mx;
    }
};

[LeetCode] String Compression 字符串压缩
 

Given an array of characters, compress it in-place.

The length after compression must always be smaller than or equal to the original array.

Every element of the array should be a character (not int) of length 1.

After you are done modifying the input array in-place, return the new length of the array.

 

Follow up:
Could you solve it using only O(1) extra space?

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), cur = 0;
        for (int i = 0, j = 0; i < n; i = j) {
            while (j < n && chars[j] == chars[i]) ++j;
            chars[cur++] = chars[i];
            if (j - i == 1) continue;
            for (char c : to_string(j - i)) chars[cur++] = c;
        }
        return cur;
    }
};

In an array A of 0s and 1s, how many non-empty subarrays have sum S?
Input: A = [1,0,1,0,1], S = 2
Output: 4
Explanation:
The 4 subarrays are bolded below:
[1,0,1]
[1,0,1,0]
[0,1,0,1]
[1,0,1]


class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int res = 0, curSum = 0;
        unordered_map<int, int> m{{0, 1}};
        for (int num : A) {
            curSum += num;
            res += m[curSum - S];
            ++m[curSum];
        }
        return res;
    }
};

LeetCode 1574. Shortest Subarray to be Removed to Make Array Sorted
Given an integer array arr, remove a subarray (can be empty) from arr
 such that the remaining elements in arr are non-decreasing.

A subarray is a contiguous subsequence of the array.

Return the length of the shortest subarray to remove
Example 1:

Input: arr = [1,2,3,10,4,2,3,5]
Output: 3
Explanation: The shortest subarray we can remove is [10,4,2] of length 3. 
The remaining elements after that will be [1,2,3,3,5] which are sorted.
Another correct solution is to remove the subarray [3,10,4].

int findLengthOfShortestSubarray(vector<int>& arr) {
	int n = arr.size(), left = 0, right = n - 1;
	while (l < n && arr[left] <= arr[left + 1] ++left;
	if (left == n - 1)
		return 0;
	while (right > left && arr[right - 1} <= arr[right])
		right--;
	int ans = min(n - left - 1, right);
	int l = 0, r = right;
	while ( l <= left && r < n) {
		if (arr[r] >= arr[l])
		{
		     ans = min(ans, r - l - 1);
		     ++l;
		} else
		     ++r;
			
	}
        return ans;
    }
	
class Solution {
 public:
  int findLengthOfShortestSubarray(vector<int>& arr) {
    const int n = arr.size();
    int l = 0;
    int r = n - 1;

    // arr[0..l] is non-decreasing.
    while (l < n - 1 && arr[l + 1] >= arr[l])
      ++l;
    // arr[r..n - 1] is non-decreasing.
    while (r > 0 && arr[r - 1] <= arr[r])
      --r;
    // Remove arr[l + 1..n - 1] or arr[0..r - 1].
    int ans = min(n - 1 - l, r);

    // Since arr[0..l] and arr[r..n - 1] are non-decreasing, we place pointers
    // at the rightmost indices, l and n - 1, and greedily shrink them towards
    // the leftmost indices, 0 and r, respectively. By removing arr[i + 1..j],
    // we ensure that arr becomes non-decreasing.
    int i = l;
    int j = n - 1;
    while (i >= 0 && j >= r && j > i) {
      if (arr[i] <= arr[j]){
        --j;
	ans = min(ans, j - i);
      }
      else
        --i;
    }

    return ans;
  }
};

Remove All Adjacent Duplicates In String

class Solution {
public:
    string removeDuplicates(string S) {
        string res;
        for (const auto& ch : S)
        {
            if (!res.empty() && (res.back() == ch))
                res.pop_back();
            else
                res += ch;
        }
        return res;
    }
};

1249. Minimum Remove to Make Valid Parentheses

Given a string s of '(' , ')' and lowercase English characters. 

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
Example 1:


string minRemoveToMakeValid(string s) {
  stack<int> st;
  for (auto i = 0; i < s.size(); ++i) {
    if (s[i] == '(') st.push(i);
    if (s[i] == ')') {
      if (!st.empty()) st.pop();
      else s[i] = '*';
    }
  }
  while (!st.empty()) {
    s[st.top()] = '*';
    st.pop();
  }
  s.erase(remove(s.begin(), s.end(), '*'), s.end());
  return s;
}


class Solution {
public:
  string minRemoveToMakeValid(string s) {    
    int close = count(begin(s), end(s), ')');    
    int open = 0;
    string ans;    
    
    for (char c : s) {
      if (c == '(') {
        if (open == close) continue;
        ++open;
      } else if (c == ')') {
        --close;
        if (open == 0) continue;
        --open;
      }
      ans += c;
    }    
    return ans;
  }
};
32. Longest Valid Parentheses

class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0, start = 0, n = s.size();
        stack<int> st;
      
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') st.push(i);
            else if (s[i] == ')') {
                if (st.empty()) start = i + 1;
                else {
                    st.pop();
                    res = st.empty() ? max(res, i - start + 1) : max(res, i - st.top());
                }
            }
        }
        return res;
    }
};

Given a string S, count the number of distinct, non-empty subsequences of S .

Since the result may be large, return the answer modulo 10^9 + 7.

Example 1:

Input: "abc"
Output: 7
Explanation: The 7 distinct subsequences are
 "a", "b", "c", "ab", "ac", "bc", and "abc".

Solution:

counts[i][j] := # of distinct sub sequences of s[1->i] and ends with letter j. 


Initialization:

counts[*][*] = 0

Transition:

counts[i][j] = sum(counts[i-1]) + 1 if s[i] == j  else counts[i-1][j]

ans = sum(counts[n])

e.g. S = “abc”

counts[1] = {‘a’ : 1}
counts[2] = {‘a’ : 1, ‘b’ : 1 + 1 = 2}
counts[3] = {‘a’ : 1, ‘b’ : 2, ‘c’: 1 + 2 + 1 = 4}
ans = sum(counts[3]) = 1 + 2 + 4 = 7

class Solution {
public:
  int distinctSubseqII(string S) {
    constexpr int kMod = 1e9 + 7;
    std::vector<int> counts(26);
    for (char c : S)
      counts[c - 'a'] = accumulate(begin(counts), end(counts), 1L) % kMod;
    return accumulate(begin(counts), end(counts), 0L) % kMod;
  }
};

674. Longest Continuous Increasing Subsequence 最长连续递增序列
 

Given an unsorted array of integers, find the length of longest continuous increasing subsequence.

Example 1:

Input: [1,3,5,4,7]
Output: 3
Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3. 
Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4. 
 


class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res = 0, cnt = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
        	if（i  == 0|| nums[i-1] < nums[i]) 
            	res = max(res, ++cnt);
            else 
            	cnt = 1;
        }
        return res;
    }
};

Squares of a Sorted Array 有序数组的平方值

Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size(), i = 0, j = n - 1;
        vector<int> res(n);
        for (int k = n - 1; k >= 0; --k) {
            if (abs(A[i]) > abs(A[j])) {
                res[k] = A[i] * A[i];
                ++i;
            } else {
                res[k] = A[j] * A[j];
                --j;
            }
        }
        return res;
    }
};


 Friend Circles 
 

There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.

Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ithand jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.

Example 1:

Input: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2
Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. 
The 2nd student himself is in a friend circle. So return 2.

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size(), cnt = 0;
        vector<bool> visited(n, false);
      
        function<void(int)> dfs = [&](int k) {
        	visited[i] = true;
        	for (int i = 0; i < n; i++) {
        		if (!M[k][i] || visited[i])
        			continue;
        		dfs(i);
        	}
        }
      
        for (int i = 0; i < n; ++i) {
            if (visited[i]) 
            	continue;
            dfs(i);
            ++cnt;
        }
        return cnt;
    }

}

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size(), res = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (visited[i]) 
            	continue;
            helper(M, i, visited);
            ++res;
        }
        return res;
    }

  
    void helper(vector<vector<int>>& M, int k, vector<bool>& visited) {
        visited[k] = true;
        for (int i = 0; i < M.size(); ++i) {
            if (!M[k][i] || visited[i]) continue;
            helper(M, i, visited);
        }
    }
};
