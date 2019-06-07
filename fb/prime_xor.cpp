Problem Summary
Given an array A with N integers between 3500 and 4500, find the number of unique multisets 
that can be formed using elements from the array such that the bitwise XOR of all
 the elements of the multiset is a prime number.

Solution

First, we notice that 3500 ≤ a[i] ≤ 4500. So the bitwise XOR of any multiset is in the range [0,(2^13)-1].

Let count[i] be the number of i in array A.
Let f[i,j] be the number of unique multisets whose elements are within [3500,i], and whose XOR equals to j. So we have

f[i,j] = ((f[i-1,j] × (count[i]/2 + 1)) % mo + (f[i-1,j^i] × ((count[i]+1)/2) % mo)) %mo

Explanation of recurrence
Suppose we have 5 duplicates of a certain value v. There are 1+5/2 ways of making an xor of 0 (take either 0,2 or 4 copies). 
here are (1+5)/2 ways of making an xor of v (take either 1,3 or 5 copies).
So to make the new value j, we can either start with j and add 0,2 or 4 copies of v, or start with j^v and add 1,3 or 5 copies



#include <cstdio>
#include <iostream>
#include <climits>
#include <cstring>
using namespace std;
const int maxn = 100002;
const int maxd = 4502;
const int mo = 1e9+7;
const int max_xor = (1<<13)-1;
int n,count[maxd];

long long f[2][max_xor+2];
vector<bool> prime(n, true);
int countPrimes(int n) {
    int res = 0;
    for (int i = 2; i < n; ++i) {
	    if (prime[i]) {
	        for (int j = 2; i * j < n; ++j) {
	                prime[i * j] = false;
	            }
	        }
    }
        return res;
}


long get_max_xor(vector<int> &nums) {
	unordered_map<int, int> m;
	for (auto a:nums) {
		m[a]++;
	}
	dp[0][0] = 1;
	int flag = 1;
	for (int i = START; i <= END;i++) {
		for (int j = 0; j <= max_xor; j++)
			if (m[i] == 0)
				dp[flag][j] = dp[1-flag][j];
			else
				dp[flag][j] = dp[1-flag][j] * (m[i]/2 + 1) %MOD  + dp[1-flag][j^i] * (m[i] + 1)/2;
		flag = 1 - flag;
	}

	long long ans = 0;
	for (int i = 0; i <= max_xor; i++) {
		if (is_prime(i))
			res += dp[1-flag][i] % MOD
	}
}
