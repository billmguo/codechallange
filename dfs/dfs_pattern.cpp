ddutput : int num（指数的最少个数）*/
ns I
 
Given a collection of numbers, return all possible permutations.
For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > coll;
        vector<int> solution;
        if (num.size()==0)
            return coll;
        GeneratePermute(num, 0, solution, coll); 
        return coll; 
    } 
    void GeneratePermute(vector<int> & num, int step, vector<int>& solution, vector<vector<int> >& coll) 
    {
      if(step>=num.size())
        return;
      if(solution.size() == num.size()) 
      { 
        coll.push_back(solution); 
        return; 
      } 
      solution.push_back(num[step]);
      GeneratePermute(num, step+1,solution,coll);
      solution.pop_back();
      GeneratePermute(num, step+1,solution,coll);
    }
};
 
Permutations II
Given a collection of numbers that might contain duplicates, return all possible unique permutations.
For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
 
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > coll; 
        vector<int> solution; 
        if(num.size() ==0) return coll; 
        vector<int> visited(num.size(), 0); 
        sort(num.begin(), num.end()); 
        GeneratePermute(num, 0, visited, solution, coll); 
        return coll; 
       } 
    void GeneratePermute(vector<int> & num, int step, vector<int>& visited, vector<int>& solution, vector<vector<int> >& coll) 
    { 
      if(step == num.size()) 
      { 
       coll.push_back(solution); 
       return; 
     } 
     for(int i =0; i< num.size(); i++) 
     { 
       if(visited[i] == 0) 
       { 
          visited[i] = 1; 
          solution.push_back(num[i]); 
          GeneratePermute(num, step+1, visited, solution, coll); 
          solution.pop_back(); 
          visited[i] =0;
          while(i<num.size()&&num[i+1]==num[i])
            i++;
        } 
      } 
  }
};
 
Permutations sequence II
The set [1,2,3,…,n] contains a total of n! unique permutations.
 
 
By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):
"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.
 
class Solution {
public:
    string getPermutation(int n, int k) {
        string ret;
        vector<int> factorial(n,1);
        vector<char> num(n,1);
       
        for(int i=1; i<n; i++)
            factorial[i] = factorial[i-1]*i;
       
        for(int i=0; i<n; i++)
            num[i] = (i+1)+'0';
       
        k--;
        for(int i=n; i>=1; i--) {
            int j = k/factorial[i-1];
            k %= factorial[i-1];
            ret.push_back(num[j]);
            num.erase(num.begin()+j);
        }
       
        return ret;
    }
};
 
subset 1
 
Given a set of distinct integers, nums, return all possible subsets.
 
Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:
 
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<int> numset; 
        vector<vector<int>> res; 
        res.push_back(numset);
        sort(S.begin(),S.end());
        subsets2(S,0,res,numset);
        return res;
    }
   
    void subsets2(vector<int>& S, int start,vector<vector<int>>&res,vector<int>& numset)
    {
        if (start >= S.size())  
            return;   
        numset.push_back(S[start]); 
        res.push_back(numset); 
        subsets2(S, start + 1, res,numset); 
        numset.pop_back(); 
        if (start + 1 < S.size()) 
            subsets2(S, start + 1, res,numset);
    }    
};
 
subsets2
 
Given a collection of integers that might contain duplicates, nums, return all possible subsets.
 
Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:
 
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
 
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
         vector<vector<int> > result; 
         vector<int> output;  
         if(S.size() ==0) return result; 
         result.push_back(output); 
         sort(S.begin(), S.end()); 
         generateSub(S, 0, result, output); 
     } 
void generateSub(vector<int> &S, int step, vector<vector<int>>&result, vector<int>&output)
{
    if (step>=S.size()) return;
    output.push_back(S[step]);
    result.push_back(output);
    generateSub(S,step+1,result,output);
    output.pop_back();
   
    while(step<S.size()-1&&S[step]==S[step+1])
        step++;
    if (step+1<S.size())
        generateSub(S,step+1,result,output);
}
 
};

subset2 

 vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > res;
        vector<int> out;
        sort(S.begin(), S.end());
        getSubsets(S, 0, out, res);
        return res;
    }
    void getSubsets(vector<int> &nums, int pos, vector<int> &out, vector<vector<int> > &res) {
    res.push_back(out);
    for (int i=pos;i<nums.size();i++)
    {
    out.push_back(nums[i]);
    getSubsets(nums,i+1,out,res);
    out.pop_back();
    while(nums[i] == nums[i+1]) i++;
    }
 }
 
combinations sum I
 
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 
The same repeated number may be chosen from C unlimited number of times.
 
Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7]
[2, 2, 3]
 
 
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> path;
        if (candidates.size()==0) return ans;
        dfs(candidates, 0, target, path, ans);
        return ans;
    }
    void dfs(vector<int>& candidates, int i, int target, vector<int> &path, vector<vector<int>> &ans)
    {
        if (target == 0)
        {
            ans.push_back(path);
            return;
        }
        if (i>=candidates.size() || candidates[i] > target) return;
        path.push_back(candidates[i]);
        dfs(candidates,i,target-candidates[i],path,ans);
        path.pop_back();
        int j=i+1;
        while(i<candidates.size() && candidates[j]==candidates[i]) j++;
        dfs(candidates, j, target, path, ans);
    }
 

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > allSol;
        vector<int> sol;
        if(candidates.empty()) return allSol;
        sort(candidates.begin(),candidates.end());
        findCombSum(candidates, 0, target, sol, allSol);
        return allSol;
    }
    
    void findCombSum(vector<int> &candidates, int start, int target, vector<int> &sol, vector<vector<int>> &allSol) {
        if(target==0) {
            allSol.push_back(sol);
            return;
        }
        
        for(int i=start; i<candidates.size(); i++) {
            if(candidates[i]<=target) {
                sol.push_back(candidates[i]);
                findCombSum(candidates, i, target-candidates[i], sol, allSol);
                sol.pop_back();
                while(nums[i] == nums[i+1]) i++;
            }
        }
    }
};

combination II
 
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 
Each number in C may only be used once in the combination.
 
Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]
 
 
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> path;
        if (candidates.size()==0) return ans;
        dfs(candidates, 0, target, path, ans);
        return ans;
    }
    void dfs(vector<int>& candidates, int i, int target, vector<int> &path, vector<vector<int>> &ans)
    {
        if (target == 0)
        {
            ans.push_back(path);
            return;
        }
        if (i>=candidates.size() || candidates[i] > target) return;
        path.push_back(candidates[i]);
        dfs(candidates,i+1,target-candidates[i],path,ans);
        path.pop_back();
        int j=i+1;
        while(i<candidates.size() && candidates[j]==candidates[i]) j++;
        dfs(candidates, j, target, path, ans);
    }
};

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > allSol;
        if(num.empty()) return allSol;
        sort(num.begin(),num.end());
        vector<int> sol;
        findCombSum2(num, 0, target, sol, allSol);
        return allSol;
    }
    
    void findCombSum2(vector<int> &num, int start, int target, vector<int> &sol, vector<vector<int> > &allSol) {
        if(target==0) {
            allSol.push_back(sol);
            return;
        }
        
        for(int i=start; i<num.size(); i++) {
            if(i>start && num[i]==num[i-1]) continue;
            if(num[i]<=target) {
                sol.push_back(num[i]);
                findCombSum2(num, i+1, target-num[i], sol, allSol);
                sol.pop_back();
                while(nums[i] == nums[i+1]) i++;
            }
        }
    }
};
 
Factor combinations, such as 24  will out put (2, 2, 6) (4, 6), (3, 8), (2,2,2,3)
 
class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> getFactors(int n) {
        vector<int> line;
        helper(n, 2, line);
        for(auto a:res){
        	for (auto b:a)
        		cout<<"*"<<b;
	        cout<<endl;		
        }
        return res;
    }
 
    void helper(int n, int start, vector<int> &item) {
        if (n == 1) {
            if (item.size() > 1) {
                res.push_back(item);
            }
            return;
        }
        for (int i = start; i <= n; i++) {
            if (n % i == 0) {
                item.push_back(i);
                helper(n/i,i,item);
                item.pop_back();
            }
        }
    }
};

