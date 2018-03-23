vector<int> longestArith(vector<int> &nums) {
        vector<int> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int maxv = 0, inc = -1, last = -1;
 
        for (int i = 1; i < nums.size() - 1; i++){
            int j = i - 1, k = i + 1;
            while (j >= 0 && k < nums.size()) {
                if (nums[j] + nums[k] > nums[i] * 2)
                    j--;
                else if (nums[j] + nums[k] < nums[i] * 2)
                    k++;
                else {
                    dp[i][k] = dp[j][i] == 0 ? 3 : dp[j][i] + 1;
                    if (dp[i][k] > maxv) {
                        maxv = dp[i][ k];
                        last = nums[k];
                        inc = nums[i] - nums[j];
                    }
 
                    j--; k++;
                }    
            }
        }
        for (int i = 0; i < maxv; i++) {
            res.insert(res.begin(),last);
            last -= inc;
        }
        return res;
 }
