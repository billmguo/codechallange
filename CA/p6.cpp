[LeetCode] 139. Word Break 拆分词句
 

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1);
        dp[0] = true;
        for (int i = 0; i < dp.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int> memo(s.size(), -1);
        return check(s, wordSet, 0, memo);
    }
    bool check(string s, unordered_set<string>& wordSet, int start, vector<int>& memo) {
        if (start >= s.size()) return true;
        if (memo[start] != -1) return memo[start];
        for (int i = start + 1; i <= s.size(); ++i) {
            if (wordSet.count(s.substr(start, i - start)) && check(s, wordSet, i, memo)) {
                return memo[start] = 1;
            }
        }
        return memo[start] = 0;
    }
};



Generate Matrix II

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int up = 0, down = n - 1, left = 0, right = n - 1, val = 1;
        while (true) {
            for (int j = left; j <= right; ++j)
            	 res[up][j] = val++;
            if (++up > down) break;
            for (int i = up; i <= down; ++i) 
            	res[i][right] = val++;
            if (--right < left) break;
            for (int j = right; j >= left; --j)
            	 res[down][j] = val++;
            if (--down < up) break;
            for (int i = down; i >= up; --i) 
            	res[i][left] = val++;
            if (++left > right) break;
        }
        return res;
    }
};

public class MaxIncome {
    public static int solution(int[][] intervals) {
        Arrays.sort(intervals, (o1, o2) -> (o1[1] - o2[1]));
        int[] dp = new int[intervals[intervals.length - 1][1] + 1];
        dp[0] = 0;
        int max = 0;
        for (int[] interval : intervals) {
            int from = interval[0];
            int to = interval[1];
            int before = 0;
            for (int i = 0; i < from; i++) {
                before = Math.max(dp[i], before);
            }
            dp[to] = Math.max(dp[to], to - from + 1 + before);
            max = Math.max(dp[to], max);
        }
        return max * 100;
    }
 
    public static void main(String[] args) {
        int[][] intervals = new int[][]{{1, 5}, {3, 7}, {6, 8}};
        System.out.println(MaxIncome.solution(intervals));
    }
}
