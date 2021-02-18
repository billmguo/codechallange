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
    public int leftMostColumnWithOne(BinaryMatrix binaryMatrix) {
        List<Integer> dimension = binaryMatrix.dimensions();
        int n = dimension.get(0);
        int m = dimension.get(1);
        int i = n - 1, j = m - 1, res = -1;
        while (i >= 0 && j >= 0) {
            int cur = binaryMatrix.get(i, j);
            if (cur == 0) {
                i--;
            } else {
                res = j;
                j--;
            }
        }
        return res;
    }

}

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
    int maxDiff = 0;
public:
    void dfs(TreeNode* node, int mx, int mn) {
        if(!node) return;
        max_d = max(max_d, abs(mx - node->val), abs(mn - node->val));
        mn = min(root->val, mn);
        mx = max(root->val, mx);
        dfs(node->left, mx, mn);
        dfs(node->right, mx, mn);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        dfs(root, root->val, root->val);
        return maxDiff;
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



class Solution {
public:
  int findLengthOfShortestSubarray(vector<int>& arr) {
    const int n = arr.size();
    int j = n - 1;
    while (j > 0 && arr[j - 1] <= arr[j]) 
    	--j;
    if (j == 0) 
    	return 0;
    int ans = j; // remove arr[0~j-1]
    for (int i = 0; i < j; ++i) {
      if (i > 0 && arr[i - 1] > arr[i]) 
      	break;
      while (j < n && arr[i] > arr[j]) ++j;      
      ans = min(ans, j - i - 1);
    }
    return ans;
  }
};
