#include <iostream>
#include <map>
#include <vector>
#include <unordered_set>
using namespace std;

int count(map<int,unordered_set<int>> &m, vector<int> &child, int start) {
	int total = 0;
	if ( 0 == child[start -1]) {
		for (auto a:m[start]) {
			total += count(m,child,a);
		}
	}
	child[start - 1] = total + 1;
	return child[start-1];
}
int main() {
	// your code goes here
	int n, m; 
	cin >> n >> m;
	vector<int> child(n,0);
	map<int, unordered_set<int>> mp;
	for (int i = 0; i < m ;i++) {
		int a, b ;
		cin >> a >> b;
		mp[b].insert(a);
	}
	count(mp,child,1);
	int evenchild = 0;
	for (int i = 1; i< n; i++) {
		if (child[i] %2 == 0)
			evenchild++;
	}
	cout<<evenchild<<endl;
	return evenchild;
}
