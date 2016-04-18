/*
Given:
int[] F of size k, with numbers in [0, k)
int a_init, within [0, k)
int N
A_0 = a_init
A_1 = F[A_0]
A_2 = F[A_1]
...
A_i = F[A_i-1]

Find A_N.
*/
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int find_nth_number(vector<int> &F, int a_init, int N) {
	map<int,int> m;
	vector<int> A(N+1,0);
	A[0] = a_init;
	for (int i = 1; i < N; i++) {
		A[i] = F[A[i-1]];
		if (m.count(A[i])) {
			int cycle = i - m[A[i]];
			return A[(N-i)%cycle + m[A[i]]];
		} else
			m[A[i]] = i;
	}
	return A[N];
}

int main() {
	// your code goes here
	vector<int> F{1,3,6,2,3,6,4};
	int res = find_nth_number(F,2,10);
	cout<<"*"<<endl;
	cout<<res<<endl;
	return 0;
}
