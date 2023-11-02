Given an array of integers preorder, which represents the preorder traversal of a 
BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search
tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any
descendant of Node.left has a value strictly less than Node.val, and any 
 descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node 
first, then traverses Node.left, then traverses Node.right.
 
    TreeNode* bstFromPreorder(vector<int>& A) {
        int i = 0;
        return build(A, i, INT_MAX);
    }

    TreeNode* build(vector<int>& A, int& i, int bound) {
        if (i == A.size() || A[i] > bound) return nullptr;
        TreeNode* root = new TreeNode(A[i++]);
        root->left = build(A, i, root->val);
        root->right = build(A, i, bound);
        return root;
    }

Given the root of a binary search tree, return a balanced binary search tree with the same node values.
 If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.
class Solution {
 public:
  TreeNode* balanceBST(TreeNode* root) {
    vector<int> nums;
    inorder(root, nums);
    return build(nums, 0, nums.size() - 1);
  }

 private:
  void inorder(TreeNode* root, vector<int>& nums) {
    if (root == nullptr)
      return;
    inorder(root->left, nums);
    nums.push_back(root->val);
    inorder(root->right, nums);
  }

  // Same as 108. Convert Sorted Array to Binary Search Tree
  TreeNode* build(const vector<int>& nums, int l, int r) {
    if (l > r)
      return nullptr;
    const int m = (l + r) / 2;
    return new TreeNode(nums[m], build(nums, l, m - 1), build(nums, m + 1, r));
  }
};


Given an integer n, find a sequence that satisfies all of the following:

The integer 1 occurs once in the sequence.
Each integer between 2 and n occurs twice in the sequence.
For every integer i between 2 and n, the distance between the two occurrences of i is exactly i.
The distance between two numbers on the sequence, a[i] and a[j], is the absolute difference of their indices, |j - i|.

Return the lexicographically largest sequence. It is guaranteed that under the given constraints, there is always a solution.

A sequence a is lexicographically larger than a sequence b (of the same length) if in the first position where a and b differ, sequence a has a number greater than the corresponding number in b. For example, [0,1,9,0] is lexicographically larger than [0,1,5,6] because the first position they differ is at the third number, and 9 is greater than 5.

 

Example 1:

Input: n = 3
Output: [3,1,2,3,2]
Explanation: [2,3,2,1,3] is also a valid sequence, but [3,1,2,3,2] is the lexicographically largest valid sequence.


// Time: O(N!)
// Space: O(N)
class Solution {
    vector<int> used;
    bool dfs(vector<int> &ans, int i) {
        if (i == ans.size()) return true; // filled all the numbers, found the answer
        if (ans[i]) return dfs(ans, i + 1); // this index is already filled, continue to fill the next index.
        for (int j = used.size() - 1; j > 0; --j) { // try each number in decending order from n to 1.
            if (used[j]) continue; // j is already used, skip
            if (j != 1 && (i + j >= ans.size() || ans[i + j])) continue; // we can't fill `ans[i + j]` either because `i + j` is out of bound or `ans[i + j]` is already filled. Skip.
            used[j] = 1; // mark number `j` as used.
            ans[i] = j; // fill `ans[j]` and `ans[i + j]` (if needed) with `j`.
            if (j != 1) ans[i + j] = j;
            if (dfs(ans, i + 1)) return true;
            ans[i] = 0; // this filling is invalid, backtrack and try the next number.
            if (j != 1) ans[i + j] = 0;
            used[j] = 0;
        }
        return false;
    }
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2 * n - 1);
        used.assign(n + 1, 0); // numbers 1 ~ n are unused initially
        dfs(ans, 0); // try filling numbers from index 0.
        return ans;
    }
};

Two strings X and Y are similar if we can swap two letters (in different positions) of X, so that it equals Y.

For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and 
"rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".

Together, these form two connected groups by similarity: {"tars", "rats", "arts"}
and {"star"}.  Notice that "tars" and "arts" are in the same group even though they are not similar.  
 Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.

We are given a list A of strings.  Every string in A is an anagram of every other string in A. 
 How many groups are there?
class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
        int res = 0, n = A.size();
        vector<int> root(n);
        for (int i = 0; i < n; ++i) root[i] = i;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (!isSimilar(A[i], A[j])) continue;
                root[getRoot(root, j)] = i;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (root[i] == i) ++res;
        }
        return res;
    }
    int getRoot(vector<int>& root, int i) {
        return (root[i] == i) ? i : getRoot(root, root[i]);
    }
    bool isSimilar(string& str1, string& str2) {
           for (int i = 0, cnt = 0; i < str1.size(); ++i) {
               if (str1[i] == str2[i]) continue;
               if (++cnt > 2) return false;
           }
           return true;
       }
};


count hills and Valley
class Solution {
 public:
  int countHillValley(vector<int>& nums) {
    int ans = 0;
    int left = nums[0];

    for (int i = 1; i + 1 < nums.size(); ++i)
      if (left < nums[i] && nums[i] > nums[i + 1] ||  // Hill
          left > nums[i] && nums[i] < nums[i + 1]) {  // Valley
        ++ans;
        left = nums[i];
      }

    return ans;
  }
};


Given a m x n matrix grid which is sorted in non-increasing order both row-wise and

column-wise, return the number of negative numbers in grid.

 class Solution {
 public:
  int countNegatives(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    int ans = 0;
    int i = m - 1;
    int j = 0;

    while (i >= 0 && j < n) {
      if (grid[i][j] < 0) {
        ans += n - j;
        --i;
      } else {
        ++j;
      }
    }

    return ans;
  }
};


Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.
Example 2:

Input: grid = [[3,2],[1,0]]
Output: 0

Problem
You are given a 0-indexed array of positive integers tasks, representing 
    tasks that need to be completed in order, where tasks[i] represents the type of the ith task.

You are also given a positive integer space, which represents the minimum 
number of days that must pass after the completion of a task before another task of the same type can be performed.

Each day, until all tasks have been completed, you must either:

Complete the next task from tasks, or

Take a break.

Return** the minimum number of days needed to complete all tasks**.
class Solution {
 public:
  long long taskSchedulerII(vector<int>& tasks, int space) {
    unordered_map<int, long long> taskToNextAvailable;
    long long ans = 0;

    for (const int task : tasks) {
      ans = max(ans + 1, taskToNextAvailable[task]);
      taskToNextAvailable[task] = ans + space + 1;
    }

    return ans;
  }
};



class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 4) return 0.0;
        double res = DBL_MAX;
        unordered_map<string, vector<vector<int>>> m;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                long dist = getLength(points[i], points[j]);
                double centerX = (points[i][0] + points[j][0]) / 2.0;
                double centerY = (points[i][1] + points[j][1]) / 2.0;
                string key = to_string(dist) + "_" + to_string(centerX) + "_" + to_string(centerY);
                m[key].push_back({i, j});
            }
        }
        for (auto &a : m) {
            vector<vector<int>> vec = a.second;
            if (vec.size() < 2) continue;
            for (int i = 0; i < vec.size(); ++i) {
                for (int j = i + 1; j < vec.size(); ++j) {
                    int p1 = vec[i][0], p2 = vec[j][0], p3 = vec[j][1];
                    double len1 = sqrt(getLength(points[p1], points[p2]));
                    double len2 = sqrt(getLength(points[p1], points[p3]));
                    res = min(res, len1 * len2);
                }
            }
        }
        return res == DBL_MAX ? 0.0 : res;
    }
    long getLength(vector<int>& pt1, vector<int>& pt2) {
        return (pt1[0] - pt2[0]) * (pt1[0] - pt2[0]) + (pt1[1] - pt2[1]) * (pt1[1] - pt2[1]);
    }
};
