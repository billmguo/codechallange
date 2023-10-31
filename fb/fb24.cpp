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
