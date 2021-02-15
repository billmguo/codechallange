Given an array A of integers, return the length of the longest arithmetic subsequence in A.

Recall that a subsequence of A is a list A[i_1], A[i_2], ..., A[i_k] with 0 <= i_1 < i_2 < ... < i_k <= A.length - 1, 

and that a sequence B is arithmetic if B[i+1] - B[i] are all the same value (for 0 <= i < B.length - 1).


class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int res = 0, n = A.size();
        vector<vector<int>> dp(n, vector<int>(2000));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int diff = A[i] - A[j] + 1000;
                dp[i][diff] = dp[j][diff] + 1;
                res = max(res, dp[i][diff]);
            }
        }
        return res + 1;
    }
};

vector<

for (int i = 0; i < n; i++) {
	for (int j = 0; j < i; j++) {
		int diff = a[i] - A[j];
		dp[i][diff] = (dp[j][diff] + 1 )
		res = max(res, dp[i][diff])
	}
}

Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:

Input: S = "aab"
Output: "aba"
Example 2:

Input: S = "aaab"
Output: ""
Note:

class Solution {
public:
    string reorganizeString(string S) {
        string res = "";
        unordered_map<char, int> m;
        priority_queue<pair<int, char>> q;
        for (char c : S) ++m[c];
        for (auto a : m) {
            if (a.second > (S.size() + 1) / 2) return "";
            q.push({a.second, a.first});
        }

       

        while (q.size() >= 2) {
            auto t1 = q.top(); q.pop();
            auto t2 = q.top(); q.pop();
            res.push_back(t1.second);
            res.push_back(t2.second);
            if (--t1.first > 0) q.push(t1);
            if (--t2.first > 0) q.push(t2);
        }
        if (q.size() > 0) res.push_back(q.top().second);
        return res;
    }
};


class Solution {
public:
    string reorganizeString(string S) {
        priority_queue<pair<int, char>> pq;
        int map[26] = { 0 };
        
        for (auto c : S) {
            if (++map[c-'a'] > (S.size() + 1)/2)
                return "";
        }
        
        for (int i = 0; i < 26; ++i) {
            if (map[i])
                pq.push({map[i], i + 'a'});
        }
        
        string ans;
        while (!pq.empty()) {
        	auto t1 = pq.top(), pq.pop();
        	ans += t1.second;
        	if (!pq.empty()) {
        		auto t2 = pq.top(), pq.pop();
        		ans += t2.second;
        		if (--t2.first)
        			pq.push(t2);
        	}
        	if (--t1.first)
        		pq.push(t1);

        }
        return ans;
    }
};

[LeetCode] 380. Insert Delete GetRandom O(1) 
 

Design a data structure that supports all following operations in average O(1) time.

 

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned
class RandomizedSet {
public:
    RandomizedSet() {}
    bool insert(int val) {
        if (m.count(val)) return false;
        nums.push_back(val);
        m[val] = nums.size() - 1;
        return true;
    }
    bool remove(int val) {
        if (!m.count(val)) return false;
        int last = nums.back();
        m[last] = m[val];
        nums[m[val]] = last;
        nums.pop_back();
        m.erase(val);
        return true;
    }
    int getRandom() {
        return nums[rand() % nums.size()];
    }
private:
    vector<int> nums;
    unordered_map<int, int> m;
};
Battership 

Given an 2D board, count how many battleships are in it. The battleships are represented with 'X's, empty slots are represented with '.'s. You may assume the following rules:

You receive a valid board, made of only battleships or empty slots.
Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.


class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return 0;
        int res = 0, m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '.' || (i > 0 && board[i - 1][j] == 'X') || (j > 0 && board[i][j - 1] == 'X')) 
                	continue;
                ++res;
            }
        }
        return res;
    }
};



688. Knight Probability in Chessboard

class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<double>> dp0(N, vector<double>(N, 0.0));
        dp0[r][c] = 1.0;
        int dirs[8][2] = {{1, 2}, {-1, -2}, {1, -2}, {-1, 2},
                          {2, 1}, {-2, -1}, {2, -1}, {-2, 1}};
        for (int k = 0; k < K; ++k) {            
            vector<vector<double>> dp1(N, vector<double>(N, 0.0));
            for (int i = 0; i < N; ++i)
                for (int j = 0; j < N; ++j) 
                    for (int m = 0; m < 8; ++m) {
                        int x = j + dirs[m][0];
                        int y = i + dirs[m][1];
                        if (x < 0 || y < 0 || x >= N || y >= N) continue;
                        dp1[i][j] += dp0[y][x];
                    }
            std::swap(dp0, dp1);
        }
        
        double total = 0;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                total += dp0[i][j];
        
        return total / pow(8, K);
    }
};


Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate 
(i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and nis at least 2.
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0, i = 0, j = height.size() - 1;
        while (i < j) {
            res = max(res, min(height[i], height[j]) * (j - i));
            height[i] < height[j]? ++i : --j;
        }
        return res;
    }
};


935. Knight Dialer

Recursive case: observe the overlapping subproblems and optimal substructure.
The current i-th hop for each keypad digit can be found from the previous i-th-minus-1 hop 
for each keypad digit which can reach the current keypad digit from a single hop. 
Therefore calculate the current i-th hop for each keypad destination digit (dst) 
as the sum of all keypad source digits (src) i-th-minus-1 hop solutions.

dp[ i ][ dst ] = sum( dp[ i-1 ][ src ] )

public:
  int knightDialer(int N) {
    constexpr int kMod = 1e9 + 7;
    vector<vector<int>> moves{{4,6},{8,6},{7,9},{4,8},{3,9,0},{},{1,7,0},{2,6},{1,3},{2,4}};
    vector<int> dp(10, 1);

    for (int k = 1; k < N; ++k) {
      vector<int> tmp(10);
      for (int i = 0; i < 10; ++i)
        for (int nxt : moves[i])
          tmp[nxt] = (tmp[nxt] + dp[i]) % kMod;        
      dp.swap(tmp);
    }
    int ans = 0;
    for (int i = 0; i < 10; ++i)
      ans = (ans + dp[i]) % kMod;
    return ans;
};


class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<double>> dp0(N, vector<double>(N, 0.0));
        dp0[r][c] = 1.0;
        int dirs[8][2] = {{1, 2}, {-1, -2}, {1, -2}, {-1, 2},
                          {2, 1}, {-2, -1}, {2, -1}, {-2, 1}};
        for (int k = 0; k < K; ++k) {            
            vector<vector<double>> dp1(N, vector<double>(N, 0.0));
            for (int i = 0; i < N; ++i)
                for (int j = 0; j < N; ++j) 
                    for (int m = 0; m < 8; ++m) {
                        int x = j + dirs[m][0];
                        int y = i + dirs[m][1];
                        if (x < 0 || y < 0 || x >= N || y >= N) continue;
                        dp1[i][j] += dp0[y][x];
                    }
            std::swap(dp0, dp1);
        }
        
        double total = 0;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                total += dp0[i][j];
        
        return total / pow(8, K);
    }
};
