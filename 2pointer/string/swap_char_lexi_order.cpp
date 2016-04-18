/*give a string and pairs can switch the char in the string
return the maxium lex order string.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
class soultion{
public:
	string swaplexorder(string &str,vector<pair<int,int>> &pairs) {
	    set<int> uset;
	    queue<pair<int,int>> q;
	    vector<char> c;
	    for (auto &pa:pairs) {
	        q.push(pa);
	    }
	    string res = str;
	    while(!q.empty()) {
	        int cur_size = q.size();
	        uset.clear();
	        for (int i = 0; i < cur_size ;i++) {
	            auto cur = q.front();
	            q.pop();
	            if( uset.empty() || uset.count(cur.first) ||uset.count(cur.second)) {
	                uset.insert(cur.first);
	                uset.insert(cur.second);
	                continue;
	            }
	            q.push(cur);
	        }
	        c.clear();
	        for (auto &e:uset){
	            c.push_back(res[e - 1]);
	        }
	        sort(c.begin(),c.end(),greater<char>());
	        auto it = uset.begin();
	        for (int i = 0 ;i < c.size(); i++) {
	    	    res[*it - 1] = c[i];
	            it++;
	        }
	    }
	    return res;
	}
};
int main() {
	// your code goes here
	string st="abcdefh";
	soultion sl;
	vector<pair<int,int>> pairs{{1,4},{2,4}, {3,6}};
	string res = sl.swaplexorder(st,pairs);
	cout<<"*"<<res<<endl;
	return 0;
}
