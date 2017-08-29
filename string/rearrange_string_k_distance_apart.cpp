
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class S1{
public:
	string rearrange(string str, int k) {
		if ( k == 0)
			return str;
		string res;
		int len = str.size();
		unordered_map<char,int> m;
		for (auto ch:str) m[ch]++;
		priority_queue<pair<int,char>> pq;
		for (auto &p:m) {
			pq.push({p.second,p.first});
		}	
		while (!pq.empty()) {
			vector<pair<int,char>> cache;
			int cnt = min(k,len);
			for (int i = 0; i < cnt; i++) {
				if (pq.empty()) return "";
				auto tmp = pq.top();
				pq.pop();
				res.push_back(tmp.second);
				if (--tmp.first)
					cache.push_back(tmp);
				len--;
			}
			for (auto p:cache)
				pq.push(p);
		}
		return res;
	}
	
};
int main() {
	S1 s;
	string str="goodboy";
	string res = s.rearrange(str, 3);
	cout <<res<<endl;
	// your code goes here
	return 0;
}
