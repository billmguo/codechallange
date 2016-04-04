/*[lintCode] Coins in a Line II 
There are n coins with different value in a line. Two players take turns to take one or two coins from left side until there are no more coins left. The player who take the coins with the most value wins.

Could you please decide the first player will win or lose?

Example
Given values array A = [1,2,2], return true.

Given A = [1,2,4], return false.

有 n 个不同价值的硬币排成一条线。两个参赛者轮流从右边依次拿走 1 或 2 个硬币，直到没有硬币为止。计算两个人分别拿到的硬币总价值，价值高的人获胜。

请判定 第一个玩家 是输还是赢？
*/
class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        int n = values.size();
        vector<int> dp(n + 1, -1);
        int sum = 0;
        for (auto v : values) sum += v;
        return sum < 2 * dfs(dp, values, n);
    }
    int dfs(vector<int> &dp, vector<int> &values, int idx) {
        if (dp[idx] != -1) return dp[idx];
        int n = values.size();
        if (idx == 0) {
            dp[idx] = 0;
        } else if (idx == 1) {
            dp[idx] = values[n-1];
        } else if (idx == 2) {
            dp[idx] = values[n-1] + values[n-2];
        } else if (idx == 3) {
            dp[idx] = values[n-2] + values[n-3];
        } else {
            int take1 = min(dfs(dp, values, idx - 2), dfs(dp, values, idx - 3)) + values[n-idx];
            int take2 = min(dfs(dp, values, idx - 3), dfs(dp, values, idx - 4)) + values[n- idx + 1] + values[n - idx];
            dp[idx] = max(take1, take2);
        }
        return dp[idx];
    }
};
/*

Coins in a Line III

There are n coins in a line. Two players take turns to take a coin from one of the ends of the line until there are no more coins left. The player with the larger amount of money wins.

Could you please decide the first player will win or lose?

Example
Given array A = [3,2,2], return true.

Given array A = [1,2,4], return true.

Given array A = [1,20,4], return false.

Challenge
Follow Up Question:

If n is even. Is there any hacky algorithm that can decide whether first player will win or lose in O(1) memory and O(n) time?

 

备忘录，dp[left][right]表示从left到right所能取到的最大值，因为双方都取最优策略，所以取完一个后，对手有两种选择，我们要加让对手得到更多value的那种方案，也就是自己得到更少value的方案。
*/

class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        int n = values.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int sum = 0;
        for (auto v : values) sum += v;
        return sum < 2 * dfs(dp, values, 0, n - 1);
    }
    int dfs(vector<vector<int>> &dp, vector<int> &values, int left, int right) {
        if (dp[left][right] != -1) return dp[left][right];
        if (left == right) {
            dp[left][right] = values[left];
        } else if (left > right) {
            dp[left][right] = 0;
        } else {
            int take_left = min(dfs(dp, values, left + 2, right), dfs(dp, values, left + 1, right - 1)) + values[left];
            int take_right = min(dfs(dp, values, left, right - 2), dfs(dp, values, left + 1, right - 1)) + values[right];
            dp[left][right] = max(take_left, take_right);
        }
        return dp[left][right];
    }
};
