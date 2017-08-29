#include <iostream>
#include <map>
#include <vector>
#include <unordered_set>
#include <queue>
#include <climits>
using namespace std;
typedef pair<int,int> pp;
void traverse(map<int, vector<pp>> &mp, vector<int> &dist) {
	dist[1] = 0;
	priority_queue<pp,vector<pp>,greater<pp>> pq; 
	pq.push(make_pair(0,1));
	while(!pq.empty()) {
		pp cur = pq.top();
		pq.pop();
		for (pp &a:mp[cur.second]) {
			int v = a.first;
			int w = a.second;
			cout<<v<<"*"<<w<<"*"<<cur.first<<endl;
			int tmp = max(w,cur.first);
			if (tmp < dist[v]) {
				dist[v] = tmp;
				pq.push(make_pair(dist[v],v));
			}

		}
	}
}

int main() {
	// your code goes here
	int n, m; 
	cin >> n >> m;
	map<int, vector<pp>> mp;
	int a, b, c;
	for (int i = 0; i < m ; i++) {
		cin >> a >> b >> c;
		mp[a].push_back(make_pair(b,c));
	}
	vector<int> dist(n + 1,INT_MAX);
	traverse(mp,dist);
	if (dist[n] != INT_MAX)
		cout<<dist[n]<<endl;
	else
		cout<<"NO PATH EXISTS"<<endl;
}
