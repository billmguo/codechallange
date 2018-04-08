node有键，值和子树。比如第一个的键是node1，值是‘aaaa'
<node1>aaaaa<node2>bbbbb</node2><node3>cccc</node3><node4>dddd</node4></node1>
第二个白人大叔主要就是聊天最后剩了点时间做了一个把：abababcdcdee变成03ab02cd01ee的压缩。都两个两个的考虑
第三个国人大哥在k个排序list里找中位数

Construct Tree from following xml
aaaa is the key of the Tree.
<node1>aaaaa<node2>bbbbb</node2><node3>cccc</node3><node4>dddd</node4></node1>. 

struct TreeNode{
	string val;
	vector<TreeNode*> child;
	TreeNode(string &t):val(t) {};
};
struct TreeNode* str2tree(string &s) {
 	if (s.empty())
 		return NULL;
 	stack<TreeNode*> st;
 	int cnt = 0;
 	for (int i = 0; i < s.size(); i++) {
 		if (s[i]== '<' ){
 		    cnt++;
 		    if (i + 1 < s.size() && s[i + 1] == '/')
 			 	st.pop();
 		}else if (s[i] =='>') {
 				cnt--;
	 			if (cnt == 0) {
	 			int j = i + 1;
	 			int t = j;
	 			//find the aaaa, bbbb,cccc ....
	 			while (j < s.size() && s[j] != '<')
	 				j++;
	 			string sub = s.substr(t, j - t);
	 			if (!st.empty()){
	 				TreeNode *node = new TreeNode(sub);
	 				if (!st.empty()) {
	 					TreeNode *cur = st.top();
	 					cur->child.push_back(node);
	 				}
	 				st.push(node);
	 			}
	 		
	 		}		
 		}
 	}
 	return st.top();
 }

find the median from k sorted list

class soultion{
private:
	priority_queue<int> maxh;
	priority_queue<int, vector<int>,greater<int>> minh;
public:
int findmedianthinksortedlist(vector<vector<int>> &arr) {
	int m = arr.size();
	int n = arr[0].size();
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			add_num(arr[i][j]);
		}
	}
	return findmedian();
	
    }
    void add_num(int num) {
    	minh.push(num);
    	maxh.push(minh.top());
    	minh.pop();
    	if (minh.size() <  maxh.size()) {
    		minh.push(maxh.top());
    		maxh.pop();
    	}
    }
    int findmedian() {
        if (minh.size() == maxh.size())
	return (minh.top() + maxh.top())/2 ;
        else
	return minh.top();
    }
};


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

Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

Examples: 
"123", 6 -> ["1+2+3", "1*2*3"] 
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []

public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        if(num.size()==0)  
            return res;
        help(res, "", num, target, 0, 0, 0);
        return res;
    }
    
    void help(vector<string> &res, string path, string num, int target, int pos,  long cur, long prev){
        if(pos == num.size()){
            if(cur == target)   
                res.push_back(path);
            return;
        }
        for (int i = pos; i < num.size(); i++) {
            if (num[pos] == '0' && i > pos) 
                break;
            string str = num.substr(pos, i - pos + 1);
            long v = stol(str);
            if (pos == 0)
                help(res, path + str, num, target, i + 1, v, v);
            else {
                help(res, path + "+" + str, num, target, i + 1, cur + v, v);
                help(res, path + "-" + str, num, target, i + 1, cur - v, -v);
                help(res, path + "*" + str, num, target, i + 1, cur - prev + prev*v, prev*v);
            }
        }
    }
};
