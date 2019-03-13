class solution{
    vector<int> parent(MAX_NODES, 0), visited(MAX_NODES,0);                  /*Keeps track of the parent of every vertex in the tree*/
    vector<vector<int> > graph;


    /*GetParents() function traverses the tree and computes the parent array such that
    The pre-order traversal begins by calling GetParents(root_node,-1) */
    void getparent(int node , int parent){ 
        if (visited(node))
            return;
        visited.insert(node);     
        for (auto a:graph[node]) {
            if (a != parent) {
                parent[a] = node;
                getparent(a, node);
            }
        } 
    }
    
   int LCA(int u , int v){
    /*traverse from node u uptil root node and mark the vertices encountered along the path . */
    int lca = -1 ; 
    fill(visited.begin(),visited.end(),0);
    while(1){
        visited[u] = true ; 
        if (u == entry_node)
            break;
        u = parent[u]; 
    }

    while(1) {
        if (visited[v]) {
            lca = v;
            break;
        }
        if (v == entry_node_2)
            break;
        v = parent[v];
    }
    return lca ; 
}
