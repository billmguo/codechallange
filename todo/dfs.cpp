 void letterCombinationsDFS(int n, vector<string>& dict, int level, string out, vector<string>& res) {
        if (level == n) {res.push_back(out); return;}
        string str = dict[level];
        for (int i = 0; i < str.size(); ++i) {
            letterCombinationsDFS(n, dict, level + 1, out + str[i], res);
        }
   }

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        const int n = stones.size();
        vroot = vector<int>(n);
        for(int i=0;i<n;i++) vroot[i] = i;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    connect(i,j);
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++) 
            if(vroot[i] == i) cnt++;
        return n - cnt;
    }
    int getRoot(int i){
        if(vroot[i] != i){
            vroot[i] = getRoot(vroot[i]);
        }
        return vroot[i];
    }
    void connect(int i, int j){
        vroot[getRoot(i)] = getRoot(j); 
    }
    
    vector<int> vroot;
};
int removemarable(vector<vector<int>> &graph) {
	int r = graph.size(), c = graph[0].size();
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			if (graph[i][j] == 1) {
				dfs(graph, i, j);
				count++;
			}
	}
	return totalCount -count;
}
void dfs(vector<vector<int>> &graph, int r, int c) {
	totalCount++;
	graph[r][c] = 0;
	for (int i = 0; i < graph.size();i++) {
		if (graph[i][c])
			dfs(graph, i , c);
	}
	for (int i = 0; i < graph[0].size(); i++) {
		if (graph[r][i])
			dfs(graph,r,i);
	}
}
