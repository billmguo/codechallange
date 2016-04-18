/*give a 3*n number, pick n number get maxium value, when pick one number
the neighbor left and right will be remove from num set too*/
#include <iostream>
#include <vector>
using namespace std;

// Recursion
class Solution {
public:
	int select(vector<int>& nums, int l, int r){
		int m = r - l + 1;
		int n = (int) (nums.size() / 3);
		vector<vector<int>> dp(m+1,vector<int>(n+1,0));
		for (int i= 1 ;i<=m;i++)
			for (int j=1;j<=n;j++)
				dp[i][j] = max(dp[i-1][j],((i<2)?0:dp[i-2][j-1]) + nums[l + i -1]);
		
		return dp[m][n];
	}
	int solve(vector<int> &nums){
		if (nums.empty() || nums.size() < 3 || (nums.size() %3 != 0))
			return 0;
		int n = nums.size();
		int dp1  = select(nums,1, n-1);
		int dp2 = select(nums,2,n);
		return max(dp1,dp2);
	}
};
    

int main() {
	// your code goes here
	Solution sl;
	vector<int> nums{1,4,1,7,4,3};
	int res = sl.solve(nums);
	cout<<res<<endl;
	return 0;
}
