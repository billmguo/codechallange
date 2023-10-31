
/*
You have n tasks and m workers. Each task has a strength requirement stored in a 0-indexed integer array tasks, with the ith task requiring tasks[i] strength to complete. The strength of each worker is stored in a 0-indexed integer array workers, with the jth worker having workers[j] strength. Each worker can only be assigned to a single task and must have a strength greater than or equal to the task's strength requirement (i.e., workers[j] >= tasks[i]).

Additionally, you have pills magical pills that will increase a worker's strength by strength. You can decide which workers receive the magical pills, however, you may only give each worker at most one magical pill.

Given the 0-indexed integer arrays tasks and workers and the integers pills and strength, return the maximum number of tasks that can be completed.

Input: tasks = [3,2,1], workers = [0,3,3], pills = 1, strength = 1
Output: 3
Explanation:
We can assign the magical pill and tasks as follows:
- Give the magical pill to worker 0.
- Assign worker 0 to task 2 (0 + 1 >= 1)
- Assign worker 1 to task 1 (3 >= 2)
- Assign worker 2 to task 0 (3 >= 3)

*/

class Solution {
 public:
  int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills,
                    int strength) {
    int ans = 0;
    int l = 0;
    int r = min(tasks.size(), workers.size());

    ranges::sort(tasks);
    ranges::sort(workers);

    // Can we finish k tasks?
    auto canComplete = [&](int k, int pillsLeft) {
      // K strongest workers
      map<int, int> m;
      for (int i = workers.size() - k; i < workers.size(); ++i)
        ++m[workers[i]];

      // Out of the k smallest tasks, start from the biggest one.
      for (int i = k - 1; i >= 0; --i) {
        // Find the first worker that has strength >= tasks[i].
        auto it = m.lower_bound(tasks[i]);
        if (it != m.end()) {
	         if (--(it->second) == 0)
	            m.erase(it);
        } else if (pillsLeft > 0) {
          // Find the first worker that has strength >= tasks[i] - strength.
	          it = m.lower_bound(tasks[i] - strength);
	          if (it != m.end()) {
	             if (--(it->second) == 0)
			              m.erase(it);
			      --pillsLeft;
	          } else {
	           	 return false;
	          }
        } else {
          	  return false;
        }
      }

        return true;
    };

    while (l <= r) {
      const int m = (l + r) / 2;
      if (canComplete(m, pills)) {
        ans = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }

    return ans;
  }
};





/*
Median is the middle value in an ordered integer list. If the size of the list is even, 
there is no middle value. So the median is the mean of the two middle value.

Examples:

[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Given an array nums , there is a sliding window of size k w
hich is moving from the very left of the array to the very right. You can only see the
 k numbers in the window. Each time the sliding window moves right by one position. Your job is t
 o output the median array for each window in the original array.

*/

class Solution {
 public:
  vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    vector<double> ans;
    multiset<double> window(nums.begin(), nums.begin() + k);
    auto it = next(window.begin(), (k - 1) / 2);

    for (int i = k;; ++i) {
      const double median = k & 1 ? *it : (*it + *next(it)) / 2.0;
      ans.push_back(median);
      if (i == nums.size())
        break;
      window.insert(nums[i]);
      if (nums[i] < *it)
        --it;
      if (nums[i - k] <= *it)
        ++it;
      window.erase(window.lower_bound(nums[i - k]));
    }

    return ans;
  }
};



/*
On an N x N grid, each square grid[i][j] represents the elevation at that point (i,j).

Now rain starts to fall. At time t, the depth of the water everywhere is t. You can
 swim from a square to another 4-directionally adjacent square if and only if the 
 elevation of both squares individually are at most t. You can swim infinite distance 
 in zero time. Of course, you must stay within the boundaries of the grid during your swim.

You start at the top left square (0, 0). What is the least time until you can 
reach the bottom right square (N-1, N-1)?


*/
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int res = 0, n = grid.size();
        unordered_set<int> visited{0};
        vector<vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        auto cmp = [](pair<int, int>& a, pair<int, int>& b) {return a.first > b.first;};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp) > q(cmp);
        q.push({grid[0][0], 0});
        while (!q.empty()) {
            int i = q.top().second / n, j = q.top().second % n; q.pop();
            res = max(res, grid[i][j]);
            if (i == n - 1 && j == n - 1) return res;
            for (auto dir : dirs) {
                int x = i + dir[0], y = j + dir[1];
                if (x < 0 || x >= n || y < 0 || y >= n || visited.count(x * n + y)) continue;
                visited.insert(x * n + y);
                q.push({grid[x][y], x * n + y});
            }
        }
        return res;
    }
};

/*There is an undirected graph with n nodes numbered from 0 to n - 1 (inclusive). You are given a 0-indexed integer array values where values[i] is the value of the ith node. You are also given a 0-indexed 2D integer array edges, where each edges[j] = [uj, vj, timej] indicates that there is an undirected edge between the nodes uj and vj, and it takes timej seconds to travel between the two nodes. Finally, you are given an integer maxTime.

A valid path in the graph is any path that starts at node 0, ends at node 0, and takes at most maxTime seconds to complete. You may visit the same node multiple times. The quality of a valid path is the sum of the values of the unique nodes visited in the path (each node's value is added at most once to the sum).

Return the maximum quality of a valid path.

Note: There are at most four edges connected to each node.*/

class Solution {
 public:
  int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges,
                         int maxTime) {
    const int n = values.size();
    int ans = 0;
    vector<vector<pair<int, int>>> graph(n);
    vector<int> seen(n);
    seen[0] = 1;

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      const int time = edge[2];
      graph[u].emplace_back(v, time);
      graph[v].emplace_back(u, time);
    }

    dfs(graph, values, 0, values[0], maxTime, seen, ans);
    return ans;
  }

 private:
  void dfs(const vector<vector<pair<int, int>>>& graph,
           const vector<int>& values, int u, int quality, int remainingTime,
           vector<int>& seen, int& ans) {
    if (u == 0)
      ans = max(ans, quality);
    for (const auto& [v, time] : graph[u]) {
      if (time > remainingTime)
        continue;
      const int newQuality = quality + values[v] * (seen[v] == 0);
      ++seen[v];
      dfs(graph, values, v, newQuality, remainingTime - time, seen, ans);
      --seen[v];
    }
  }
};


for (const auto & [v, time]:graph[u]) {
	if (time > remainingTime) {
		continue;
	}
	int nq = qaultiy + values[v]*(seen[v] == 0);
	++seen[v];
	dfs(graph, values, v, nq, remainingTime - time, seen, ans)
	--seen[v];
}



C++

 Given a 2D integer array nums, return all elements of nums in diagonal order as shown in the below images.

class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    vector<int> ans;
    unordered_map<int, vector<int>> keyToNums;  // Key = row + col
    int maxKey = 0;

    for (int i = 0; i < nums.size(); ++i)
      for (int j = 0; j < nums[i].size(); ++j) {
        const int key = i + j;
        keyToNums[key].push_back(nums[i][j]);
        maxKey = max(maxKey, key);
      }

    for (int i = 0; i <= maxKey; ++i)
      for (auto it = keyToNums[i].rbegin(); it != keyToNums[i].rend(); ++it)
        ans.push_back(*it);

    return ans;
  }
};


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

/* An array nums of length n is beautiful if:

nums is a permutation of the integers in the range [1, n].
For every 0 <= i < j < n, there is no index k with i < k < j where 2 * nums[k] == nums[i] + nums[j].
Given the integer n, return any beautiful array nums of length n. There will be at least one valid answer for the given n.

*/

class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int> res{1};
        while (res.size() < N) {
            vector<int> t;
            for (int num : res) {
                if (num * 2 - 1 <= N) t.push_back(num * 2 - 1);
            }
            for (int num : res) {
                if (num * 2 <= N) t.push_back(num * 2);
            }
            res = t;
        }
        return res;
    }
};




