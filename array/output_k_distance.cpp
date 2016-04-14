nclude <iostream>
#include <unordered_set>
using namespace std;

string output(string s, int k){
	unordered_set<int> visited;
	string res;
	int len = s.size();
	int pos = 0;
	int cnt = 0;
	while(visited.size() != len ){
		if (!visited.count(pos)) {
			cnt++;
			cout<<s[pos]<<"*"<<cnt<<endl;
			if (cnt == k && !visited.count(pos)){
				visited.insert(pos);
				cout<<s[pos]<<endl;
				res.push_back(s[pos]);
				cnt = 0;
			}
		}
		pos = (pos + 1) % len;
	}
	return res;
}

