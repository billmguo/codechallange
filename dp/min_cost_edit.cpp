/*the cost definition is the space to the end of line, given a word length, output the min cost*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution{
public:	
	int mincost(vector<int> &wordlens, int width) {
		if (wordlens.empty())
			return 0;
		int n = wordlens.size();
		vector<int> cost(n + 1,INT_MAX);
		cost[0] = 0;
		for (int i = 0; i < n; i++) {
			int space = width - wordlens[i];
			update(cost,i, i+1, space);
			for (int j = i + 1;j < n && space > wordlens[j]; j++) {
				space -= wordlens[j] + 1 ;
				update(cost,i, j + 1, space);
			}
		}
		for (auto a:cost)
			cout<<a<<" ";
		cout<<endl;
		return cost[n];
	}
	void update(vector<int>& cost, int i, int j, int space) {
		int tmp = cost[i] + space*space;
		if (cost[i] < 0 || cost[j] > tmp )
			cost[j] = tmp;
	}
};
int main() {
	Solution sl;
	vector<int> words{4,3,3,2};
	int len = 8;
	int res = sl.mincost(words,len);
	cout<<res<<endl;
	// your code goes here
	return 0;
}
