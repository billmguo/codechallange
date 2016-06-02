/*using on to detect whether a substring in a number can divide 36 r 1*/
#include <iostream>
#include <set>
using namespace std;

bool containnumber(string &str, int num) {
	set<char> uset;
	for (auto ch:str) {
		if (!isdigit(ch))
			uset.clear();
		else{
			set<char> nset;
			int r  = ch - '0';
			nset.insert(r);
			for (auto a:uset){
				int v = (a * 10 + r) % num;
				if (v == 1)
					return true;
				nset.insert(a); 
			}
			uset = nset;
		}
	}
}
int main() {
	// your code goes here
	string test{"361"};
	bool res = containnumber(test, 36);
	cout<<res<<endl;
	return 0;
}
