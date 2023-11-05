
1143. Longest Common Subsequence
Given two strings text1 and text2, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string with some 
characters(can be none) deleted without changing the relative order of the remaining characters.
(eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings
is a subsequence that is common to both strings.

 

If there is no common subsequence, return 0.
class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    const int m = text1.length();
    const int n = text2.length();
    // dp[i][j] := LCS's length of text1[0..i) and text2[0..j)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 0; i < m; ++i){
      for (int j = 0; j < n; ++j){
         if (text[i] == text2[j)
             dp[i + 1][j + 1] = 1 + dp[i][j];
         else{
             dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i+1][j]; 
         }
      }
    }

    return dp[m][n];
  }
};

1062. Longest Repeating Substring
Given a string S, find out the length of the longest repeating
 substring(s). Return 0 if no repeating substring exists.

 

Example 1:

Input: "abcd"
Output: 0
Explanation: There is no repeating substring.
Example 2:

Input: "abbaba"
Output: 2
Explanation: The longest repeating substrings are
 "ab" and "ba", each of which occurs twice.



class Solution {
 public:
  int longestRepeatingSubstring(string s) {
    const int n = s.length();
    int ans = 0;
    // dp[i][j] := # of repeating chars of s[0..i) and s[0..j)
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; ++i)
      for (int j = i + 1; j <= n; ++j)
        if (s[i - 1] == s[j - 1]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
          ans = max(ans, dp[i][j]);
        }

    return ans;
  }
};

Given a string s, find the longest palindromic subsequence’s length in s. You may assume that the maximum length of s is 1000.
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
Given a string s, return the longest palindromic substring in s. //not subsequence
 
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int n = s.size(), left = 0, len = 1;
        vector<vector<bool>> dp(n, vector<bool>(n));     
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
            for (int j = 0; j < i; ++j) {
                dp[j][i] = (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1]));
                if (dp[j][i] && len < i - j + 1) {
                    len = i - j + 1;
                    left = j;
                }
            }
        }
        return s.substr(left, len);
    }
};
You have a pointer at index 0 in an array of size arrLen. At each step, you can move 1 position to the left, 1 position to the right in the array or stay in the same place  (The pointer should not be placed outside the array at any time).

Given two integers steps and arrLen, return the number of ways such that your pointer still at index 0 after exactly steps steps.

Since the answer may be too large, return it modulo 10^9 + 7


class Solution {
 public:
  int numWays(int steps, int arrLen) {
    constexpr int kMod = 1'000'000'007;
    const int n = min(arrLen, steps / 2 + 1);
    // dp[i] := # of ways to stay on index i
    vector<long> dp(n);
    dp[0] = 1;

    while (steps--) {
      vector<long> newDp(n);
      for (int i = 0; i < n; ++i) {
        newDp[i] = dp[i];
        if (i - 1 >= 0)
          newDp[i] += dp[i - 1];
        if (i + 1 < n)
          newDp[i] += dp[i + 1];
        newDp[i] %= kMod;
      }
      dp = move(newDp);
    }

    return dp[0];
  }
};

dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]
dp[0][0] = 1

 int numWays(int steps, int arrLen) {
        int kMod = 1000000007;
        int n = min(arrLen, steps + 1);
        long[][] dp = new long[steps + 1][n];
        dp[0][0] = 1;
        for (int i = 1; i <= steps; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j + 1 < n)
                    dp[i][j] += dp[i - 1][j + 1];
                if (j - 1 >= 0)
                    dp[i][j] += dp[i - 1][j - 1];
                dp[i][j] %= kMod;
            }
        }
        return (int) dp[steps][0];
    }


1011

A conveyor belt has packages that must be shipped from one port to another within D days.

The i-th package on the conveyor belt has a weight of weights[i].  Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within D d


class Solution {
 public:
  int shipWithinDays(vector<int>& weights, int days) {
    int l = ranges::max(weights);
    int r = accumulate(weights.begin(), weights.end(), 0);

    while (l < r) {
      const int m = (l + r) / 2;
      if (shipDays(weights, m) <= days)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

 private:
  int shipDays(const vector<int>& weights, int shipCapacity) {
    int days = 1;
    int capacity = 0;
    for (const int weight : weights)
      if (capacity + weight > shipCapacity) {
        ++days;
        capacity = weight;
      } else {
        capacity += weight;
      }
    return days;
  };
};


  
leetcode 918

Here, a  circular array  means the end of the array connects to the beginning of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)

Also, a subarray may only include each element of the fixed buffer A at most once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)

 class Solution {
 public:
  int maxSubarraySumCircular(vector<int>& nums) {
    int totalSum = 0;
    int currMaxSum = 0;
    int currMinSum = 0;
    int maxSum = INT_MIN;
    int minSum = INT_MAX;

    for (const int num : nums) {
      totalSum += num;
      currMaxSum = max(currMaxSum + num, num);
      currMinSum = min(currMinSum + num, num);
      maxSum = max(maxSum, currMaxSum);
      minSum = min(minSum, currMinSum);
    }

    return maxSum < 0 ? maxSum : max(maxSum, totalSum - minSum);
  }
};

Given an array consists of non-negative integers, your task is to count the number of
triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int res = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = n - 1; i >= 2; --i) {
            int left = 0, right = i - 1;
            while (left < right) {
                if (nums[left] + nums[right] > nums[i]) {
                    res += right - left;
                    --right;
                } else {
                    ++left;
                }
            }
        }
        return res;
    }
};



/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *  public:
 *   vector<string> getUrls(string url);
 * };
 */
/*
Given a URL startUrl and an interface HtmlParser, implement a Multi-threaded web crawler to crawl all links that are under the same hostname as startUrl.

Return all URLs obtained by your web crawler in any order.

Your crawler should:

Start from the page: startUrl
Call HtmlParser.getUrls(url) to get all URLs from a webpage of a given URL.
Do not crawl the same link twice.
Explore only the links that are under the same hostname as startUrl.
  */

class Solution {
 public:
  vector<string> crawl(string startUrl, HtmlParser htmlParser) {
    queue<string> q{{startUrl}};
    unordered_set<string> seen{{startUrl}};
    const string& hostname = getHostname(startUrl);

    // Threading
    const int nThreads = std::thread::hardware_concurrency();
    vector<thread> threads;
    std::mutex mtx;
    std::condition_variable cv;

    auto t = [&]() {
      while (true) {
        unique_lock<mutex> lock(mtx);
        cv.wait_for(lock, 30ms, [&]() { return q.size(); });
        if (q.empty())
          return;
        auto cur = q.front();
        q.pop();
        lock.unlock();
        const vector<string> urls = htmlParser.getUrls(cur);
        lock.lock();
        for (const string& url : urls) {
          if (seen.count(url))
            continue;
          if (url.find(hostname) != string::npos) {
            q.push(url);
            seen.insert(url);
          }
        }
        lock.unlock();
        cv.notify_all();
      }
    };

    for (int i = 0; i < nThreads; ++i)
      threads.emplace_back(t);

    for (std::thread& t : threads)
      t.join();

    return {seen.begin(), seen.end()};
  }

 private:
  string getHostname(const string& url) {
    const int firstSlash = url.find_first_of('/');
    const int thirdSlash = url.find_first_of('/', firstSlash + 2);
    return url.substr(firstSlash + 2, thirdSlash - firstSlash - 2);
  }
};

leetcode 1053
Given an array of positive integers arr (not necessarily distinct),
 return  the lexicographically largest permutation that is
  smaller than  arr, that can be made with exactly one swap
(A  swap  exchanges the positions of two numbers arr[i] and arr[j]). If it cannot be done, then return the same array.

Example 3:

Input: arr = [1,9,4,6,7]
Output: [1,7,4,6,9]
Explanation: Swapping 9 and 7.
复制代码
Example 4:

Input: arr = [3,1,1,3]
Output: [1,3,1,3]
Explanation: Swapping 1 and 3.


class Solution {
 public:
  vector<int> prevPermOpt1(vector<int>& arr) {
    const int n = arr.size();
    int l = n - 2;
    int r = n - 1;

    while (l >= 0 && arr[l] <= arr[l + 1])
      l--;
    if (l < 0)
      return arr;
    while (arr[r] >= arr[l] || arr[r] == arr[r - 1])
      r--;
    swap(arr[l], arr[r]);

    return arr;
  }
};


1057. Campus Bikes
On a campus represented as a 2D grid, there are N workers and M bikes, with N <= M. Each worker and bike is a 2D coordinate on this grid.

Our goal is to assign a bike to each worker. Among the available bikes and workers, we choose the (worker, bike) 
pair with the shortest Manhattan distance between each other, and assign the bike to that worker. (If there are multiple (worker, bike) pairs with
 the same shortest Manhattan distance, we choose the pair with the smallest worker index; 
 if there are multiple ways to do that, we choose the pair with the smallest bike index). 
We repeat this process until there are no available workers.

The Manhattan distance between two points p1 and p2 is Manhattan(p1, p2) = |p1.x - p2.x| + |p1.y - p2.y|.

Return a vector ans of length N, where ans[i] is the index (0-indexed) of the bike that the i-th worker is assigned to.
 
 For each iteration, loop over the workers and loop over 
 the bikes to find the shortest Manhattan distance between a worker and a bike. If there is a tie, always 
 keep the smallest worker index and the smallest bike index. After the (worker, bike) pair is determined, 
 assign the bike to the worker, and set both the worker and the bike as assigned. In the following iterations, 
 if a worker or a bike is already assigned, then skip the worker or the bike. Continue the process until each 
 	worker is assigned a bike.



class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& W, vector<vector<int>>& B) {
        int N = W.size(), M = B.size();
        vector<array<int, 3>> v;
        auto dist = [](auto &a, auto &b) {
            return abs(a[0] - b[0]) + abs(a[1] - b[1]);
        };
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                v.push_back({dist(W[i], B[j]), i, j});  // i is bike j is worker.  
            }
        }
        vector<bool> used(M);
        sort(begin(v), end(v));
        vector<int> ans(N, -1);
        for (int i = 0, cnt = 0; i < v.size() && cnt < N; ++i) {
            if (used[v[i][2]] || ans[v[i][1]] != -1) continue;
            used[v[i][2]] = true;
            ans[v[i][1]] = v[i][2];
            ++cnt;
        }
        return ans;
    }
};


1498. Number of Subsequences That Satisfy the Given Sum Condition (Medium)
Given an array of integers nums and an integer target.

Return the number of non-empty subsequences of nums such that the 
sum of the minimum and maximum element on it is less or equal than target.

Since the answer may be too large, return it modulo 10^9 + 7.

Consider input nums = [3,5,6,7], target = 9.

For 3, we can find the maximum number we can use which is 6.
 So we get a subarray [3,5,6]. Then how many subsequences starting with this 3
  we can form using this subarray? It should be 2^(len - 1) = 2^2 = 4 because out of [5, 6], 
  we just can choose to pick zero, one or two of them.

Then we consider the next element 5, and the right bound should only decrease 
so that we can still sum up to 9. So we can use two pointers, i scanning elements from left to right,
 and j starting from N - 1 and scanning leftwards to find the maximum right boundary.


 class Solution {
 public:
  int numSubseq(vector<int>& nums, int target) {
    constexpr int kMod = 1e9+7;
    const int n = nums.size();
    int ans = 0;
    vector<int> pows(n, 1);  // pows[i] = 2^i % kMod

    for (int i = 1; i < n; ++i)
      pows[i] = pows[i - 1] * 2 % kMod;

    sort(nums.begin(), nums.end());

    for (int l = 0, r = n - 1; l <= r;)
      if (nums[l] + nums[r] <= target) {
        ans += pows[r - l];
        ans %= kMod;
        ++l;
      } else {
        --r;
      }

    return ans;
  }
};

 

