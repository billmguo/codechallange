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


