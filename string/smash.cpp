/*given a target word and check whether the word is smashable, smashable means the word in the dict and remove one alpha each time and remain word are still in dict
the soultino does not use dfs*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <list>
using namespace std;

class Solution{
public:	
	vector<unordered_set<string>> as;
	void init(vector<string> &words) {
		unordered_map<int, unordered_set<string>> m;
		for (auto w:words) {
			int key = w.size();
			m[key].insert(w);
		}
		
		unordered_set<string> zero;
		zero.insert("");
		as.push_back(zero);
		for (int ks = 1; !m[ks].empty(); ks++) {
			unordered_set<string> curr = smash(m[ks],as[ks-1]);
			if (!curr.empty())
				as.push_back(curr);
			else
				break;
		}
	
	}
	unordered_set<string> smash(unordered_set<string> &cur, unordered_set<string> &prevs) {
		unordered_set<string> ans;
		for (auto word:cur) {
			for (int i = 0; i < word.size() ;i++){
				string smash = word.substr(0,i) + word.substr(i+1);
				if (prevs.count(smash)) {
					ans.insert(word);
					break;
				}
			}
		}
		return ans;
	} 
	bool issmashable(string word) {
		return word.size() < as.size() && as[word.size()].count(word);
	}
};
int main() {
	// your code goes here
	vector<string> words={
		"hello","hell","ell","el","e"
	};
	Solution sl;
	sl.init(words);
	bool res = sl.issmashable("hello");
	cout<<res<<endl;
	return 0;
}
