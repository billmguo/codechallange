int numWays(int n, int k) {
        if (n == 0) 
            return 0;
        int same = 0, diff = k, res = same + diff;
        for (int i = 1; i < n; ++i) {
            same = diff;
            diff = res * (k - 1);
            res = same + diff;
        }
        return res;
}
int numWays(int n, int k) {
        if(n == 0)
            return 0;
        vector<int> same(n, 0);
        vector<int> diff(n, 0);
        same[0] =  0;
        diff[0] =  k;
        for(int i = 1; i < n; i++){
            same[i] = diff[i-1];
            diff[i] = (diff[i-1] + same[i-1]) * (k-1);
        }
        return same[n - 1] + diff[n - 1];
}
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] <'1' || s[0] > '9')
            return 0;
        vector<int> dp(s.size() + 1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 1; i < s.size();i++) {
            if (!isdigit(s[i]))
                return 0;
            int v = (s[i - 1] -'0')  * 10 + (s[i] - '0');
            if (v > 9 && v <= 26)
                dp[i + 1] += dp[i - 1];
            if (s[i] != '0')
                dp[i + 1] += dp[i];
        }
        return dp.back();
    }
};
