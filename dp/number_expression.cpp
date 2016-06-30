/*assume a number can be express with 0, 1 ,2, how many express way can it be, like 
4 could be 100, 20, 12, 8 is 1000 200, 112*/

int expressway(int x){
	if (x < 0) 
		x = - x;
	if (x < 2)
		return 1;
	vector<int> dp(x + 1 , 0);
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= x; i++) {
		if ( (i & 1 ) == 1) 
			dp[i] = dp[i >> 1];
		else
			dp[i] = dp[i>>1] + dp[(i >> 1) - 1]; 
	}
}
