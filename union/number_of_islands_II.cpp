nclude <iostream>
#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int,int>> &positions) {
        vector<int> res;
        if (m <= 0 || n <= 0) return res;
        vector<int> roots(m * n, -1);
        int cnt = 0;
        vector<vector<int> > dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        for (auto a : positions) {
            int id = n * a.first + a.second;
            roots[id] = id;
            ++cnt;
            for (auto d : dirs) {
                int x = a.first + d[0], y = a.second + d[1];
                int cur_id = n * x + y;
                if (x < 0 || x >= m || y < 0 || y >= n || roots[cur_id] == -1) continue;
                int new_id = findRoots(roots, cur_id);
                if (id != new_id) {
                    roots[new_id] = id;
                   // id = new_id;
                    --cnt;
                }
            }
            res.push_back(cnt);
        }
        return res;
    }
    int findRoots(vector<int> &roots, int id) {
        while (id != roots[id]) {
            roots[id] = roots[roots[id]];
            id = roots[id];
        }
        return id;
    }
};
int main() {
	vector<pair<int, int>> moves{make_pair(0,0),make_pair(0,1),make_pair(1,2), make_pair(2,1)};
	int m = 3, n = 3;
	Solution sl;
	vector<int> res;
	res = sl.numIslands2(m,n,moves);
	for(auto num:res)
		cout<<num<<"*";
	//cout<<res<<endl;
	// your code goes here
	return 0;
}
