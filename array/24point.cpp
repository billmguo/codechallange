nclude <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class soultion{
public:
	vector<int> dfs(vector<int> &nums, int target, int start, int end){
		vector<int> res;
		if (start > end )
			return res;
		for (int i = start; i < end ;i++){
			vector<int> left = dfs(nums,target,start, i);
			vector<int> right = dfs(nums,target,i+1,end);
			for (auto l:left)
				for (auto r:right){
					res.push_back(l+r);
					res.push_back(l*r);
					if (r!=0)
						res.push_back(l/r);
					res.push_back(l-r);
				}
	
		}
		return res;
	}
	
	void gensets(vector<vector<int>> &res, int step, vector<int> &sol, vector<int> &nums, vector<bool> visited){
			if (sol.size () == nums.size()){
				res.push_back(sol);
				return;
			}
			for (int i=0;i<nums.size();i++){
				if(visited[i] == 0) {  
			          visited[i] = 1;  
			          sol.push_back(nums[i]);  
			          gensets(res, step+1, sol, nums, visited);  
			          sol.pop_back();  
			          visited[i] =0;
			          while(i<nums.size()&&nums[i+1] == nums[i]) 
			            i++; 
		        }
			}
	}
	
	bool canget24(vector<int> &nums, int target){
		if (nums.empty())
			return false;
		sort(nums.begin(),nums.end());
		vector<bool> visited(nums.size(),false);
		vector<vector<int>> res;
		vector<int> sol;
		gensets(res,0,sol,nums,visited);
		for (auto &cand:res){
			vector<int> path = dfs(cand,target,0,cand.size()-1);
			for (auto i:path)
				if (i == target)
					return true;
		}
		return false;
	}
};

int main(){
	return 0;
}

