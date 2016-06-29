/*given a node list, each node has index to its parent in the index in the array, parent node must be in child node left , root is in the index 0
and its p_index is -1, remove the Kth node and its subtree, and move remain nodes to left, set remain NULL*/

#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int parent;
	Node(int parent):parent(parent){};
};
void remove(vector<Node*> nodelist, int k) {
	if (nodelist.empty() || k > nodelist.size())
		return;
	int n = nodelist.size();
	vector<int> index(n,0);
	for (int i = 0; i < n ; i++)
		index[i] = i;
	nodelist[k] = NULL;
	int slot = 1;
	for (int i = k + 1 ; i < n ; i++) {
		if (nodelist[i] != NULL && nodelist[nodelist[i]->parent] == NULL)
			nodelist[i] = NULL;
		if (nodelist[i] == NULL)
			slot++;
		else
			index[i] -= slot;
	}
	for (int i = k, j = k+1; j < n;j++) {
		if (nodelist[j] == NULL)
			continue;
		swap(nodelist[i],nodelist[j]);
		++i;
	}
}
