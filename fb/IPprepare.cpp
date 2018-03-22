node有键，值和子树。比如第一个的键是node1，值是‘aaaa'
<node1>aaaaa<node2>bbbbb</node2><node3>cccc</node3><node4>dddd</node4></node1>
第二个白人大叔主要就是聊天最后剩了点时间做了一个把：abababcdcdee变成03ab02cd01ee的压缩。都两个两个的考虑
第三个国人大哥在k个排序list里找中位数

 TreeNode* str2tree(string &s) {
 	if (s.empty())
 		return NULL;
 	stack<TreeNode*> st;
 	for (int i = 0; i < s.size(); i++) {
 		if (s[i]= '<' && s[i + 1] == '/')
 			 st.pop();
 		else if (s[i] == '>') {
 			int j = t = i + 1;
 			//find the aaaa, bbbb,cccc ....
 			while (j < s.size() && s[j] != '<')
 				j++;
 			sub = s.substr(t, j - t);
 			if (!t.empty()){
 				TreeNode *node = new TreeNode(t);
 				if (!st.empty())
 					TreeNode *cur = st.top();
 					if (!cur->left) 
 						cur->left = node;
 					else
 						cur->right = node;
 				st.push(node);
 			}
 		}
 	}
 	return st.top();
 }

int findmedianthinksortedlist(vector<vector<int>> &arr) {
	int m = arr.size();
	int n = arr[0].size();
	int k = 0;
	k = (m + n) % 2;
	typedef pair<int, pp<int,int>> tpp;
	for (int i = 0; i < arr.size();i++)
		pq.push({arr[i][0],{i, 0}});
	priority_queue<tpp, vector<tpp>,greater<tpp>> pq;
	while(!pq.size() <= k) {
		auto t = pq.top();
		pq.pop();
		if (t.second.second + 1  < arr[0].size())
			pq.push(arr[t.second.frist][t.second.second + 1],{t.second.first, t.second.second + 1})
	}
	if ((m + n) % 2 == 1) {
		res = pq.top().first;
	}else{
		a1 = pq.pop().first;
		a2 = pq.push(newitem).first;
		res = (a1  + a2)/2;
	}
}


string compression(string &s) {
	string res;
	if (s.size() <= 2){
		res += "01" + s;
		return res;
	}
	string prev = s.substr(0,2);
	for (int i = 2; i < res.size(); i += 2) {
		string t = s.substr(i,2);
		if (t == prev) {
			cnt++;			
		}else{
			res += to_string(cnt) + t;
			cnt = 1;
		}
		prev = t;
	}
	res += to_string(cnt) + prev;
}



 int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        dfs(root, res);
        return res;
 }
int dfs(TreeNode* node, int& res) {
	if (!node) return 0;
	int left = max((dfs(node->left), res), 0);
	int right = max((dfs(node->right), res), 0);
	res = max(res, left + right + node->val);
	return max(left, right) + node->val;
}


void subsets(vector<int> &nums, int pos, vector<int> &out) {
	if (pos >= nums.size())
		return;
	out.push_back(nums);
	printv(out);
	subsets(nums, pos + 1, out);
	out.pop_back(nums);
	subsets(nums, pos + 1, out);

}

printv(out);
for (int i = pos, i < nums.size(); i++) {
	out.push_back(nums[i]);
	subsets(nums, i + 1, out, res)
	out.pop_back();
}

  r，然后问的是first unique character in a strinbg

  char findunique(string &s) {
  	char res = 0xFF;
  	int cnt[256];
   	for (int i = 0; i < s.size(); i++) {
  		if (char == 0xFF && !m.count(s[i])) {
  			res = s[i];
  		}
  		m[s[i]]++;
  	}
  	return res;
  }

