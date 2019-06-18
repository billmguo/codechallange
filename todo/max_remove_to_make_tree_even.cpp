Maximum edge removal from tree to make even forest
Given an undirected tree which has even number of vertices, we need to
 remove the maximum number of edges from this tree such that each connected
  component of the resultant forest has an even number of vertices.



1) Do DFS from any starting node as tree is connected.
2) Initialize count of nodes in subtree rooted under current node as 0.
3) Do following recursively for every subtreeof current node.
    a) If size of current subtree is even,increment result by 1 as we can 
       disconnect the subtree.
    b) Else add count of nodes in current subtree to current count.

int dfs(vector<vector<int>> &g, int u, vector<bool> visit, int& res) 
{ 
    visit[u] = true; 
    int cur = 0; 
  
    //  iterate over all neighbor of node u 
    for (auto a:g[cur]) {
    	if (visited[a]) continue;
    	int sub_count = dfs(g, a, visit, res);
    	if (sub_connt %2 == 0)
    		res++;
    	else
    		cur ++ sub_connt;
    }
    // number of nodes in current component and one for 
    // current node 
    return cur + 1; 
} 
  
/*  method returns max edge that we can remove, after which 
    each  connected component will have even number of 
    vertices */
int maxEdgeRemovalToMakeForestEven(vector<vector<int>> &g, int N) 
{ 
    // Create a visited array for DFS and make all nodes 
    // unvisited in starting 
    bool visit[N + 1]; 
    for (int i = 0; i <= N; i++) 
        visit[i] = false; 
  
    int res = 0; // Passed as reference 
  
    //  calling the dfs from node-0 
    dfs(g, 0, visit, res); 
  
    return res; 
} 
