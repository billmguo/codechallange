#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;
class soultion{
public:
	vector<string> wordchain(vector<string> &dict){
		vector<string> res;
		if (dict.size() == 0)
			return res;
		map<int, vector<string>> umap;
		for (auto &en:dict) {
			int len = en.size();
			umap[len].push_back(en);
		}
		unordered_set<string> used;
		queue<vector<string>> q;

		for (auto &m:umap.begin()->second){
			vector<string> q_entry;
			q_entry.push_back(m);
			q.push(q_entry);
			used.insert(m);
		}

		int max_size = 1;
		int cur_size = 1;
		while (!q.empty()) {
			int curqsize = q.size();
			for (int i = 0; i < curqsize ;i++) {
				auto cur = q.front();
				q.pop();
				int curlen = cur.back().size();
				vector<string> m = find(cur.back(), umap[curlen + 1],used);
				if (!m.empty()){
					for(auto &next:m) {
						vector<string> tmp = cur;
						tmp.push_back(next);
						if (tmp.size() > max_size)
							res = tmp;
						q.push(tmp);	
					}
					cur_size++;
				}
			}
			for (auto &en:umap[cur_size]){
				if (!used.count(en))
					used.insert(en);	
			}	
		}
		return res;

	}

	bool onedistance(string &cur, string &dest) {
		if (dest.size() != cur.size() + 1)
			return false;
		vector<int> cnt(256, 0);
		for (int i=0; i < cur.size();i++) {
			cnt[cur[i]]++;
		}
		bool once = false;
		for (int i=0; i< dest.size();i++) {
			cnt[dest[i]]--;
			if (cnt[dest[i]] < 0) {
				if (!once)
					once = true;
				else 
					return false; 
			}
		}
		return true;
	}

	vector<string> find(string &cur, vector<string> &st,unordered_set<string> &used) {
		vector<string> res;
		for (int i = 0;i< st.size();i++) {
			if (!used.count(st[i]) && onedistance(cur,st[i]))
				res.push_back(st[i]);
		}
		return res;
	}
};

int main() {
	// your code goes here
	vector<string> dict{"i", "in", "on", "min", "sin","sing","sink","string","sting"};
	soultion sl;
	vector<string> res= sl.wordchain(dict);
	for (auto &en:res)
		cout<<en<<" ";
	return 0;
}
