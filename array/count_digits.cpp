/*count the occurence of digit k less than n*/
#include <iostream>
using namespace std;

int digitcounts(int k, int n) {
	int count = 0;
	int base = 1;
	int res = 0;
	while (n/base >= 1) {
		int higher =  n / (base * 10);
		int cur  =  (n % (base * 10)) / base;
		int lower  = n % base;
		cout<<higher << "*" << cur << "*" << lower<<endl;
		if ( cur == k) {
			res += higher * base  + lower + 1;
		}else if (cur < k)
			res += higher * base;
		else
			res += (higher + 1)*base;
		base *= 10;
	}
	return res;
}


int main() {
	// your code goes here
	int res = digitcounts(2, 24);
	cout<<res<<endl;
	return 0;
}
