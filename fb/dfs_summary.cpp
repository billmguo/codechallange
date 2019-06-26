Firstly, the Combination Sum 1 & 4 are similar, and Combination Sum 2 & 3 are similar !!! Combination Sum 3 is the special case of Combination Sum 2, and the Combination Sum 4 return the count while Combination Sum return all the combination !
k sum problem is a good extension for the combination sum problem, k-sum 1 is to return the count while k-sum 2 return all the possible results

DP: when solve the problem return the count

DFS : for return all the possible result

Update@08/05/2016 :

There are 2 more interesting problem, let us check it now !

k Sum 1 & 2

return the count Given n distinct positive integers, integer k (k <= n) and a number target. Find k numbers where sum is target. Calculate how many solutions there are?
return alll
Solution to ksum-1 :

class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
    int kSum(vector<int> A, int k, int target) {
        // wirte your code here
        const int n = A.size();
        /** dp[i][j][target] : # of ways to start from vector[0..i-1], choose j elements to sum to target **/
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(target + 1, 0)));
        
        for(int i = 1; i <= n; i++) {
            if(A[i-1] <= target) {
                for(int j = i; j <= n; j++) {
                    dp[j][1][A[i-1]] =1;
                }
            }
        }
        /** for position i, we can choose it or not **/
        for(int i = 1; i <= n; i++) {
            for(int j = min(i, k); j > 1; j--) {
                for(int p = 1; p <= target; p++) {
                    dp[i][j][p] = dp[i - 1][j][p];
                    if(p - A[i - 1] >= 0) {
                        dp[i][j][p] += dp[i - 1][j - 1][p - A[i - 1]];
                    }
                }
            }
        }
        return dp[n][k][target];
    }
};
Update @ 2016/09/07
There is a more easy to grasp solution :

class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
int kSum(vector<int> A, int k, int target) {
        // wirte your code here
        const int n = A.size();
        /** dp[i][j][target] : # of ways to start from vector[0..i-1], choose j elements to sum to target **/
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(target + 1, 0)));
        
        for(int i = 0; i < A.size(); i++) {
            dp[i][0][0] = 1;
        }
        /** for position i, we can choose it or not **/
        for(int i = 1; i <= n; i++) {
            for(int j =1; j <= k; j++) {
                for(int p = 1; p <= target; p++) {
                    if (j > i) dp[i][j][p] = 0; 
                    else dp[i][j][p] = dp[i-1][j][p];
                    if(p - A[i - 1] >= 0) {
                        dp[i][j][p] += dp[i - 1][j - 1][p - A[i - 1]];
                    }
                }
            }
        }
        return dp[n][k][target];
    }
};
Solution to ksum-2 :

class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return a list of lists of integer
     */
    vector<vector<int>> kSumII(vector<int> A, int k, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(A, k, 0, target, curr, ans);
        return ans;
    }

    void helper(vector<int> A, int k, int start, int target, vector<int>& curr, vector<vector<int>> & ans) {
        if (k < 0 || target < 0) {
            return;
        }

        if (k == 0 && target == 0) {
            ans.emplace_back(curr);
            return;
        }

        for (int i = start; i <= A.size() - k; i++) {
            curr.emplace_back(A[i]);
            helper(A, k - 1, i + 1, target - A[i], curr, ans);
            curr.pop_back();
        }
    }
};
Problem 39 Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T. The same repeated number may be chosen from C unlimited number of times.

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> combination;
        dfs(candidates, target, result, combination, 0);
        return result;
    }
    
    void dfs(vector<int>& nums, int target, vector<vector<int>>& result, vector<int>& combination, int begin) {
        if (!target) {
            result.push_back(combination);
            return;
        }
        for (int i = begin; i < nums.size() && target >= nums[i]; i++) {
            combination.push_back(nums[i]);
            dfs(nums, target - nums[i], result, combination, i);
            combination.pop_back();
        }
    }
};
Problem 40 Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T. Each number in C may only be used once in the combination.

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> combination;
        dfs(candidates, target, result, combination, 0);
        return result;
    }
    
    void dfs(vector<int>& nums, int target, vector<vector<int>>& result, vector<int>& combination, int begin) {
        if (!target) {
            result.push_back(combination);
            return;
        }
        for (int i = begin; i < nums.size() && target >= nums[i]; i++) {
            combination.push_back(nums[i]);
            //combinationSum1 : dfs(nums, target - nums[i], result, combination, i);
            dfs(nums, target - nums[i], result, combination, i + 1);
            combination.pop_back();
            //combinationSum1 : no this line to filter the duplicate cases 
            while (i < nums.size() && nums[i] == nums[i+1]) i++;
        }
    }
};
Problem 216 Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

This problem is different from the 1 & 2, our choice is constrained to be [1,9], and our target is valid, then our bigest number is just sum from 1 to 9, our result is that number 1 to 9 can only be choosed for one time. All in all, this problem is a special case of the Combination Problem 2

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(1, path, result, k, n);
        return result;
    }
    
    void dfs(int pos, vector<int>& path, vector<vector<int>>& result, int k, int n) {
        //cut edge
        if (n < 0) return;
        //valid cases
        if (n == 0 && k == path.size()) result.push_back(path);
        for (int i = pos; i <= 9; i++) {
            path.push_back(i);
            dfs(i + 1, path, result, k, n - i);
            path.pop_back();
        }
    }
};
Problem 377 Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

This problem is just similar to the Combination Problem 1 , we only need to return the count but not all the possible result .

dp[i] : record the possible combination count to sum to target value of i
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;
        sort (nums.begin(), nums.end());
        for (int i = 1; i <= target; i++) {
            for (auto num : nums) {
                if (i < num) break;
                dp[i] += dp[i - num];
            }
        }
        return dp.back();
    }
};
Problem 77 Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

This problem is the almost same as the problem Combination sum 2, only with different ending conditions !

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> path;
        dfs(1, path, res, n, k);
        return res;
    }
    void dfs(int pos, vector<int> &path, vector<vector<int> > &res, int n, int k) {
        if (path.size() == k) res.push_back(path);
        else {
            for (int i = pos; i <= n; ++i) {
                path.push_back(i);
                dfs(i + 1, path, res, n, k);
                path.pop_back();
            }
        }
    }
};
Problem 17 Letter Combination Given a digit string, return all possible letter combinations that the number could represent. A mapping of digit to letters (just like on the telephone buttons) is given below.

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;
        vector<string> dict{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        dfs(digits, dict, 0, "", res);
        return res;
    }
    void dfs(string digits, vector<string>& dict, int pos, string path, vector<string> &res) {
        if (pos == digits.size()) res.push_back(path);
        else {
            string str = dict[digits[pos] - '0'];
            for (int i = 0; i < str.size(); ++i) {
                path.push_back(str[i]);
                dfs(digits, dict, pos + 1, path, res);
                path.pop_back();
            }
        }
    }
};
Problem 254 Write a function that takes an integer n and return all possible combinations of its factors. Note: Each combination's factors must be sorted ascending, for example: The factors of 2 and 6 is [2, 6], not [6, 2]. You may assume that n is always positive.

class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> result;
        vector<int> path;
        helper(n, 2, path, result);
        return result;
    }
    void helper(int remain, int start, vector<int> path, vector<vector<int>> &result) {
        if (remain == 1) {
            if (path.size() > 1) result.push_back(path);
        } else {
            for (int i = start; i <= remain; ++i) {
                if (remain % i == 0) {
                    path.push_back(i);
                    helper(remain / i, i, path, result);
                    path.pop_back();
                }
            }
        }
    }
};
