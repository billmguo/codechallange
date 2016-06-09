/*give a matrix, the value is the height , if current rain is high than bar, the water
can passover, rain start from 0x0 and add one each day and calculat how long there can have
one path from src to dst*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

typedef pair<int,int> pp;
typedef tuple<int,int,int> tp;

int solve(vector<vector<int>> &mat, pp &src, pp &dst) {
	if (mat.size() == 0)
		return -1;
	int row = mat.size();
	int col = mat[0].size();
	int curval, curx, cury;

	vector<pp> dirs{{0,1},{0,-1},{-1,0},{1,0}};
	vector<vector<bool>> visited(row,vector<bool>(col,false));
	priority_queue<tp,vector<tp>,greater<tp>> pq;
	tuple<int,int,int> t = make_tuple(mat[src.first][src.second],src.first,src.second);
	pq.push(t);
	visited[src.first][src.second] = true;
	int ans = -1;
	while (!pq.empty()) {
		auto curt = pq.top();
		tie (curval, curx, cury) = curt;
		cout<<curval<<curx<<cury<<endl;
		pq.pop();
		ans = max(ans,curval);
		if (curx == dst.first && cury == dst.second)
			break;
		for (auto dir:dirs) {
			int x = curx + dir.first;
			int y = cury + dir.second;
			if (x < 0 || x >= row || y < 0 || y >= col || visited[x][y])
				continue;
			visited[x][y] = true;
			auto t = make_tuple(mat[x][y],x,y);
			pq.push(t);
		}
	}
	return ans;
}
int main() {
	// your code goes here
	vector<vector<int>> matrix = {{9,0,10},{2,7,8},{1,5,2}};
	pp start = {2,1};
	pp end ={0,1};
	int res = solve(matrix,start,end);
	cout<<res<<endl;
	return 0;
}
