class Solution{
public:
	int depthSum(vector<NestedInteger>& nestedlist) {
		return dfs(nestedlist,1);
	}
	int dfs(vector<NestedInteger>& nestedlist, int depth) {
		int ans = 0;
		for (auto nl:nestedlist) {
			if (nl.isInteger()) 
				ans += depth * nl.getInteger();
			else
				ans += dfs(n1.getList(), depth + 1);
		}
	}
};
