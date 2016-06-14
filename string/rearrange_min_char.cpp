#include <iostream>
#include <stack>

using namespace std;

string minkdistance(string &s, int k) {
	if (s.size() == 0 || s.size() < k)
		return s;
	string res;
	stack<int> st, st1;
	for (int i = 0; i < s.size() ;i++) {
		while (!st.empty() && s[st.top()] > s[i] && i - st.top()<= k) {
			st1.push(st.top());
			st.pop();
		}
		st.push(i);
		while(!st1.empty()){
			st.push(st1.top());
			st1.pop();
		}
	}

	while (!st.empty()) {
		res = s[st.top()] + res;
		st.pop();
	}
	return res;
}
int main() {
	// your code goes here
	int k = 2;
	string s="google";
	string res = minkdistance(s,k);
	cout<<res<<endl;
	return 0;
}
