/* rearrange the array according to the fixed sequeence, how many sequence can return the orignal sequeue*/
/*like 1,3,2, 0, we need move the number in position 1 to the position 0, and number in position 3 to 2, position 2 in position 2,
sequeue not change but input change*/
#include <iostream>
#include <vector>
using namespace std;
int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b,a%b);
}
int lcm(int a, int b) {
	return a * b /gcd(a,b);
}
int minrearrange(vector<int> &pattern) {
	int n = pattern.size();
	vector<bool> visited(n,false);
	int ans = 1;
	for (int i = 0; i < n ;i++) {
		if (visited[i])
			continue;
		int j = i, k = 0;
		while(true) {
			visited[j] = true;
			k++;
			j = pattern[j];
			if (j == i) 
				break;
			if (j < 0 || j >= n || visited[j])
				return -1;
		}
		ans = lcm(ans,k);
	}
	return ans;
}
int main() {
	// your code goes here
	vector<int> pattern{1,3,2,0};
	int res = minrearrange(pattern);
	cout<<res<<endl;
	return 0;
}
