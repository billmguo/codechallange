https://www.hackerrank.com/challenges/rust-murderer
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <map>
#include <climits>
using namespace std;

void bfsc(map<int,unordered_set<int>>  &m, vector<int> &dist, int start) {
	queue<int> q;
	unordered_set<int> unvisited;
	for (int i = 1 ; i < dist.size(); i++)
		if (i != start)
			unvisited.insert(i);

	dist[start] = 0;
	q.emplace(start);
	while(!q.empty() && !unvisited.empty()) {
		int cur = q.front();
		q.pop();
		for (auto it = unvisited.begin();it != unvisited.end();) {
			if (!m[cur].count(*it)) {
				dist[*it] = dist[cur] + 1;
				q.push(*it);
				it = unvisited.erase(it);
				if (unvisited.empty())
					return;
			}else{
				it++;
			}
		}
	}
}
int main() {
	// your code goes here
	int t;
	cin >> t;
	int n, e;
	map<int,unordered_set<int>> mp;
	
	for (int i = 0 ; i < t ; i++) {
		cin >> n;
		cin >> e;
		for (int j = 0; j < e; j++) {
			int s, d;
			cin >> s >> d;
			mp[s].insert(d);
			mp[d].insert(s);
		}
	}
	int start;
	cin >> start;
	vector<int> dist(n + 1,INT_MAX);
	bfsc(mp,dist,start);
	for (int i = 1; i < n + 1; i++) {
		if (i != start)
			cout<<dist[i]<<" ";
	}
	cout<<endl;
	return 0;
}
