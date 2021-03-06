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

class Solution {
public:
    Solution(vector<int> w) {
        sum = w;
        for (int i = 1; i < w.size(); ++i) {
            sum[i] = sum[i - 1] + w[i];
        }
    }
    
    int pickIndex() {
        int x = rand() % sum.back(), left = 0, right = sum.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (sum[mid] <= x) left = mid + 1;
            else right = mid;
        }
        return right;
    }
    
private:
    vector<int> sum;
};
