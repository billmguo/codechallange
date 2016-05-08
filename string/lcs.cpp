#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s1,s2;
    cin >> s1;
    cin >> s2;
    int len1 = s1.size();
    int len2 = s2.size();
    string path;
   	vector<vector<int>> dp(len1 + 1,vector<int>(len2 + 1, 0));
    for (int i = 0;i < len1 ;i++){
    	for (int j = 0;j < len2; j++) {
	       	 if (s1[i] == s2[j]){
			     dp[i+1][j+1] = dp[i][j] + 1;
	       	 }    
		     else
			     dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
	    }
    }
    int index = dp[len1][len2];
    int i = len1, j= len2;
    string res;
    while( i >= 0 && j>=0) {
    	if (s1[i-1] == s2[j-1]){
    		res = string(1,s1[i-1]) + res;
    		i--,j--;
    	}else if (dp[i-1][j] > dp[i][j-1])
    		i--;
    	else
    		j--;
    }
    cout<<res<<endl;
    return 0;
}
