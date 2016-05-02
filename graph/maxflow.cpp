#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <climits>
using namespace std;

class FordFulkerson {
public:
   int maxFlow(vector<vector<int>> &capacity, int source, int sink){

        //declare and initialize residual capacity as total avaiable capacity initially.
        vector<vector<int>> residualCapacity = capacity;
    
        //this is parent map for storing BFS parent
        map<int,int> parent;

        //stores all the augmented paths
        vector<vector<int>> augmentedPaths;

        //max flow we can get in this network
        int maxFlow = 0;

        //see if augmented path can be found from source to sink.
        while(BFS(residualCapacity, parent, source, sink)){
            vector<int> augmentedPath;
            int flow = INT_MAX;
            //find minimum residual capacity in augmented path
            //also add vertices to augmented path list
            int v = sink;
            while(v != source){
                augmentedPath.push_back(v);
                int u = parent[v];
                if (flow > residualCapacity[u][v]) {
                    flow = residualCapacity[u][v];
                }
                v = u;
            }
            augmentedPath.push_back(source);
            reverse(augmentedPath.begin(),augmentedPath.end());
            augmentedPaths.push_back(augmentedPath);

            //add min capacity to max flow
            maxFlow += flow;
		    //decrease residual capacity by min capacity from u to v in augmented path
            // and increase residual capacity by min capacity from v to u
            v = sink;
            while(v != source){
                int u = parent[v];
                residualCapacity[u][v] -= flow;
                residualCapacity[v][u] += flow;
                v = u;
            }
        }
        printAugmentedPaths(augmentedPaths);
        return maxFlow;
    }

    /**
     * Prints all the augmented path which contribute to max flow
     */
    void printAugmentedPaths(vector<vector<int>> &augmentedPaths) {
        cout<<"Augmented paths"<<endl;
        for (auto &path:augmentedPaths) {
        	for (auto &p:path)
        		cout<<p<<"*";
        	cout<<endl;
        }
    }

    /**
     * Breadth first search to find augmented path
     */
    bool BFS(vector<vector<int>> &residualCapacity, map<int,int> &parent,
            int source, int sink){
        unordered_set<int> visited;
        queue<int> q;
        q.push(source);
        visited.insert(source);
        bool foundAugmentedPath = false;
        //see if we can find augmented path from source to sink
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v = 0; v < residualCapacity.size(); v++){
                //explore the vertex only if it is not visited and its residual capacity is
                //greater than 0
                if(!visited.count(v) &&  residualCapacity[u][v] > 0){
                    //add in parent map saying v got explored by u
                    //parent[v] = u;
                    parent[v] = u;
                    //add v to visited
                    visited.insert(v);
                    //add v to queue for BFS
                    q.push(v);
                    //if sink is found then augmented path is found
                    if ( v == sink) {
                        foundAugmentedPath = true;
                        break;
                    }
                }
            }
        }
        //returns if augmented path is found from source to sink or not
        return foundAugmentedPath;
    }
 
};

int main() {
	// your code goes here
	 FordFulkerson ff;
     vector<vector<int>> capacity = {{0, 3, 0, 3, 0, 0, 0},
                            {0, 0, 4, 0, 0, 0, 0},
                            {3, 0, 0, 1, 2, 0, 0},
                            {0, 0, 0, 0, 2, 6, 0},
                            {0, 1, 0, 0, 0, 0, 1},
                            {0, 0, 0, 0, 0, 0, 9},
                            {0, 0, 0, 0, 0, 0, 0}};

    cout<<"Maximum capacity " << ff.maxFlow(capacity, 0, 6);
	return 0;
}
