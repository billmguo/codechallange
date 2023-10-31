class UnionFind {
 public:
  UnionFind(int n) : id(n), rank(n) {
    iota(id.begin(), id.end(), 0);
  }

  void unionByRank(int u, int v) {
    const int i = find(u);
    const int j = find(v);
    if (i == j)
      return;
    if (rank[i] < rank[j]) {
      id[i] = j;
    } else if (rank[i] > rank[j]) {
      id[j] = i;
    } else {
      id[i] = j;
      ++rank[j];
    }
  }

  int find(int u) {
    return id[u] == u ? u : id[u] = find(id[u]);
  }

 private:
  vector<int> id;
  vector<int> rank;
};

You are given an integer n indicating the number of people in a network. Each person is labeled from 0 to n - 1.

You are also given a 0-indexed 2D integer array restrictions, where restrictions[i] = [xi, yi] 
means that person xi and person yi cannot become friends, either directly or indirectly through other people.

Initially, no one is friends with each other. You are given a list of friend requests as a 
0-indexed 2D integer array requests, where requests[j] = [uj, vj] is a friend request between person uj and person vj.

A friend request is successful if uj and vj can be friends. Each friend request is processed 
in the given order (i.e., requests[j] occurs before requests[j + 1]), and upon a successful request, uj 
and vj become direct friends for all future friend requests.

Return a boolean array result, where each result[j] is true if the jth friend request is successful or false if it is not.

Note: If uj and vj are already direct friends, the request is still successful.
class Solution {
 public:
  vector<bool> friendRequests(int n, vector<vector<int>>& restrictions,
                              vector<vector<int>>& requests) {
    vector<bool> ans;
    UnionFind uf(n);

    for (const vector<int>& request : requests) {
      const int i = uf.find(request[0]);
      const int j = uf.find(request[1]);
      bool isValid = true;
      if (i != j)
        for (const vector<int>& restriction : restrictions) {
          const int x = uf.find(restriction[0]);
          const int y = uf.find(restriction[1]);
          if (i == x && j == y || i == y && j == x) {
            isValid = false;
            break;
          }
        }
      ans.push_back(isValid);
      if (isValid)
        uf.unionByRank(i, j);
    }

    return ans;
  }
};

There are n people standing in a queue, and they numbered from 0 to n - 1 in 
 left to right order. You are given an array heights of distinct integers 
where heights[i] represents the height of the i-th person.
 A person can see another person to their right in the queue if 
everybody in between is shorter than both of them. More formally,
 the i-th person can see the j-th person if i < j and min(heights[i], heights[j]) >
max(heights[i+1], heights[i+2], ..., heights[j-1]).

Return an array answer of length n where answer[i] is the number 
of people the i-th person can see to their right in the queue.


class Solution {
 public:
  vector<int> canSeePersonsCount(vector<int>& heights) {
    const int n = heights.size();
    vector<int> ans(n);
    stack<int> stack;

    for (int i = 0; i < n; ++i) {
      while (!stack.empty() && heights[stack.top()] <= heights[i])
        ++ans[stack.top()], stack.pop();
      if (!stack.empty())
        ++ans[stack.top()];
      stack.push(i);
    }

    return ans;
  }
};


K Radius Subarray Averages


class Solution {
 public:
  vector<int> getAverages(vector<int>& nums, int k) {
    const int n = nums.size();
    const int size = 2 * k + 1;
    vector<int> ans(n, -1);
    if (size > n)
      return ans;

    long sum = accumulate(nums.begin(), nums.begin() + size, 0L);

    for (int i = k; i + k < n; ++i) {
      ans[i] = sum / size;
      if (i + k + 1 < n)
        sum += nums[i + k + 1] - nums[i - k];
    }

    return ans;
  }
};

You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.

A uni-value grid is a grid where all the elements of it are equal.

Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.

class Solution {
public:
  int minOperations(vector<vector<int>>& grid, int x) {
    const int mn = grid.size() * grid[0].size();    
    vector<int> nums;
    nums.reserve(mn);
    for (const auto& row : grid)
      nums.insert(end(nums), begin(row), end(row));
    nth_element(begin(nums), begin(nums) + mn / 2, end(nums));
    const int median = nums[mn / 2];
    int ans = 0;
    for (int v : nums) {
      if (abs(v - median) % x) return -1;
      ans += abs(v - median) / x;
    }
    return ans;
  }
};

1909. Remove One Element to Make the Array Strictly Increasing

class Solution {
 public:
  bool canBeIncreasing(vector<int>& nums) {
    bool removed = false;

    for (int i = 1; i < nums.size(); ++i)
      if (nums[i - 1] >= nums[i]) {
        if (removed)
          return false;
        removed = true;  // Remove nums[i - 1]
        if (i > 1 && nums[i - 2] >= nums[i])
          nums[i] = nums[i - 1];  // Remove nums[i] instead
      }

    return true;
  }
};

1331. Rank Transform of an Array

class Solution {
 public:
  vector<int> arrayRankTransform(vector<int>& arr) {
    vector<int> sortedArr(arr);
    unordered_map<int, int> rank;

    sort(sortedArr);

    for (const int a : sortedArr)
      if (!rank.count(a))
        rank[a] = rank.size() + 1;

    for (int& a : arr)
      a = rank[a];

    return arr;
  }
};


1826. Faulty Sensor

class Solution {
 public:
  int badSensor(vector<int>& sensor1, vector<int>& sensor2) {
    const bool oneDefect = canReplace(sensor2, sensor1);
    const bool twoDefect = canReplace(sensor1, sensor2);
    if (oneDefect && twoDefect)
      return -1;
    if (!oneDefect && !twoDefect)
      return -1;
    return oneDefect ? 1 : 2;
  }

 private:
  bool canReplace(const vector<int>& A, const vector<int>& B) {
    int i = 0;  // A's index
    int j = 0;  // B's index
    int droppedValue = -1;

    while (i < A.size())
      if (A[i] == B[j]) {
        ++i;
        ++j;
      } else {
        droppedValue = A[i];
        ++i;
      }

    return j == B.size() - 1 && B[j] != droppedValue;
  }
};


