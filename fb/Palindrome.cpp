the longest longestPalindrome
class Solution {
public:
    string longestPalindrome(string s) {
        int dp[s.size()][s.size()] = {0}, left = 0, right = 0, len = 0;
        for (int i = 0; i < s.size(); ++i) {
            dp[i][i] = 1;
            for (int k = 0; k < i; ++k) {
                dp[k][i] = (s[i] == s[k] && (i - k < 2 || dp[k + 1][i - 1]));
                if (dp[k][i] && len < i - k + 1) {
                    len = i - k + 1;
                    left = k;
                    right = i;
                }
            }
        }
        return s.substr(left, right - left + 1);
    }
};

Given a string, your task is to count how many palindromic substrings in this string.
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size() , res = 0;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = true;
            res++;
            for (int j = 0; j < i; ++j) {
                dp[j][i] = (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1]));
                if (dp[j][i])
                    res++;
            }
        }
        return res;
    }
};
