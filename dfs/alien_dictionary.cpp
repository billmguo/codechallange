nclude <iostream>
#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;
bool dfs(unordered_map<char, unordered_set<char>>& g, unordered_set<char>& visited, unordered_set<char>& rec, string& order, char n);
string alienOrder(vector<string>& words);
string topsort(unordered_map<char, unordered_set<char>>& g);

bool dfs(unordered_map<char, unordered_set<char>>& g, unordered_set<char>& visited, unordered_set<char>& rec, string& order, char n) {
    if (rec.count(n)) return false;
    if (visited.count(n)) return true;

    visited.insert(n);
    rec.insert(n);

    for (auto iter = g[n].begin(); iter != g[n].end(); ++iter)
        if (dfs(g, visited, rec, order, *iter) == false)
            return false;

    rec.erase(n);
    order.push_back(n);

    return true;
}

string topsort(unordered_map<char, unordered_set<char>>& g) {
    unordered_set<char> visited;
    unordered_set<char> rec;
    string order;

    for (auto &neigh:g) {
        if (!visited.count(neigh.first)&&!dfs(g, visited, rec, order,neigh.first))
        {
        	order.clear();
            return "";
        }    
    }

    reverse(order.begin(), order.end());
    return order;
}

string alienOrder(vector<string>& words) {
    if (words.size() == 1) return words.front();

    unordered_map<char, unordered_set<char>> g;
    for (int i = 1; i < words.size(); i++) {
        string t1 = words[i - 1];
        string t2 = words[i];           
        bool found = false;
        for (int j = 0; j < max(t1.length(), t2.length()); j++) {
            if (j < t1.length() && g.count(t1[j]) == 0)
                g.insert(make_pair(t1[j], unordered_set<char>()));
            if (j < t2.length() && g.count(t2[j]) == 0)
                g.insert(make_pair(t2[j], unordered_set<char>()));
            if (j < t1.length() && j < t2.length() && t1[j] != t2[j] && !found) {
                g[t1[j]].insert(t2[j]);
                found = true;
            }
        }
    }


   return topsort(g);
}
int main() {
	// your code goes here
	vector<string> words{"baa", "abcd", "abca", "cab", "cad"};
	string order;
	order = alienOrder(words);
	cout<<order<<endl;
	return 0;
}
