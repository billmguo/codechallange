Battleship

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        for(int i=0;i<board.size();++i)
            for(int j=0;j<board[i].size();++j) {
                if(board[i][j] == 'X'
                   && (i==0 || board[i-1][j] == '.')
                   && (j==0 || board[i][j-1] == '.')) 
		   ++count;
            }
        return count;
    }
};

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int n = A.size();
        vector<int> dp(n + 1, 0);
        for(int i=1; i <= n; i++) {
            int curm=0;
            for(int j = i-1; j >= 0 &&j >= i-K ; j--) {
                curm = max(curm, A[j]);
                dp[i] = max(dp[i], dp[j] + curm * (i - j));
            }
        }
        return dp.back();
    }
};

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};


class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > res;
        vector<int> out;
        sort(S.begin(), S.end());
        dfs(S, 0, out, res);
        return res;
    }
    void dfs(vector<int> &S, int pos, vector<int> &out, vector<vector<int> > &res) {
        if (out.size() >= 2) {
            if (*min_element(out) + *max_element(out) == target)
                res.push_back(out);
        }
        res.push_back(out);
        for (int i = pos; i < S.size(); ++i) {
            out.push_back(S[i]);
            dfs(S, i + 1, out, res);
            out.pop_back();
        }
    }
};
/*sub two string*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	void removefirstzero(string &str) {
		while(*str.begin() == '0')
			str.erase(str.begin());
	}
    bool isSmaller(string str1, string str2) { 
    // Calculate lengths of both string 
	 int n1 = str1.length(), n2 = str2.length(); 
	 if (n1 < n2)  return true; 
     if (n2 > n1) return false; 
  	 for (int i=0; i<n1; i++)  { 
	        if (str1[i] < str2[i]) 
	            return true; 
	        else if (str1[i] > str2[i]) 
	            return false; 
	  } 
	  return false; 
    } 
    string subStrings(string num1, string num2) {
        string res = "";
        removefirstzero(num1);
        removefirstzero(num2);
        if (isSmaller(num1, num2))
        	swap(num1, num2);
        int m = num1.size(), n = num2.size(), i = m - 1, j = n - 1, carry = 0;
        while (i >= 0 || j >= 0) {
            int a = i >= 0 ? num1[i--] - '0' : 0;
            int b = j >= 0 ? num2[j--] - '0' : 0;
            int sum = a - b - carry;
            if (sum < 0) {
            	sum = sum + 10;
            	carry = 1;
            } else {
            	carry = 0;
            }
            res.insert(res.begin(), sum + '0');
        }
        while(*res.begin() == '0')
        	res.erase(res.begin());
        return res;
    }
};
int main() {
	// your code goes here
	Solution sl;
	string res = sl.subStrings("0099","88");
	cout<<res<<endl;
	return 0;
}
class Solution {
public:
    int findComplement(int num) {
        int mask = INT_MAX;
        while (mask & num) mask <<= 1;
        return ~mask & ~num;
    }
};


class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return find(n, n);
    }
    vector<string> find(int m, int n) {
        vector<string> res;
        if (m == 0) return {""};
        if (m == 1) return {"0","1","8"};
        vector<string> t = find(m - 2, n);
        for (auto a:t) {
            if (m != n)
                res.push_back("0" + a + "0");
            res.push_back("1" + a + "1");
            res.push_back("6" + a + "9");
            res.push_back("8" + a + "8");
            res.push_back("9" + a + "6");
        }
        return res;
    }
};



[LeetCode] Maximum Swap 最大置换

1 9 9 3

9 9 9 3  (back数组)

9 9 1 3

class Solution {
public:
    int maximumSwap(int num) {
        string res = to_string(num), back = res;
        for (int i = back.size() - 2; i >= 0; --i) {
            back[i] = max(back[i], back[i + 1]);
        }
        for (int i = 0; i < res.size(); ++i) {
            if (res[i] == back[i]) continue;
            for (int j = res.size() - 1; j > i; --j) {
                if (res[j] == back[i]) {
                    swap(res[i], res[j]);
                    return stoi(res);
                }
            }
        }
        return stoi(res);
    }
};

for (int i = 0; i < s.size(); i++) {
    if isdigit(s[i])
        len = len * 10 + s[i] - '0'
    else

}

Gernerate generateAbbreviations
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        helper(word, 0, 0, "", res);
        return res;
    }
    void helper(string word, int pos, int cnt, string out, vector<string> &res) {
        if (pos == word.size()) {
            if (cnt > 0)
                out += to_string(cnt);
            res.push_back(out);
        } else {
            helper(word, pos + 1, cnt + 1, out, res);
            helper(word, pos + 1, 0, out + (cnt > 0 ? to_string(cnt) : "") + word[pos], res);
        }
    }
};

[LeetCode] Valid Word Abbreviation 验证单词缩写
 

Given a non-empty string s and an abbreviation abbr, return whether the string matches with the given abbreviation.

A string such as "word" contains only the following valid abbreviations:

["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]


class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int m = word.size(), n = abbr.size(), p = 0, cnt = 0;
        for (int i = 0; i < abbr.size(); ++i) {
            if (isdigit(abbr[i])) {
                if (cnt == 0 && abbr[i] == '0') return false;
                cnt = 10 * cnt + abbr[i] - '0';
            } else {
                p += cnt;
                if (p >= m|| word[p++] != abbr[i])
                    return false;
                cnt = 0;
            }
        }
        return p + cnt == m;
    }
};


Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:

Input:nums = [1,1,1], k = 2
Output: 2

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, sum = 0, n = nums.size();
        unordered_map<int, int> m{{0, 1}};
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            res += m[sum - k];
            ++m[sum]; 
        }
        return res;
    }
};


array of points [[1,3], [2,5], [3,3], [1,0], [1,1], [5,5]], target = k
求 k nearest neighbors for (0, 0) 



typedef pair<int, int> pp;
int distance(pp &a, pp& b) {
    int t = a.first - b.first;
    int m = a.second - b.secon;
    return t*t + m *m;
}
vector<pp> knn(vector<pp> &points) {
    priority_queue<pp> pq;
    vector<pp> res;
    pp basepoint = {0, 0};
    for (int i = 0; i < points.size(); i++) {
        pq.push({distance(points[i],basepoint), i});
        if (pq.size() > k)
            pq.pop();
    }
    while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        res.push_back(points[t.second]);
    }
    return res;
}

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, cur = 0, cnt = 0;
        for (int num : nums) {
            ++cnt;
            if (num == 0) {
                cur = cnt;
                cnt = 0;
            } 
            res = max(res, cnt + cur);
        }
        return res;
    }
};



Input: [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]

vector<string> summaryRanges(vector<int>& nums) {
    const int size_n = nums.size();
    vector<string> res;
    if ( 0 == size_n) return res;
    for (int i = 0; i < size_n;) {
        int start = i, end = i;
        while (end + 1 < size_n && nums[end+1] == nums[end] + 1) end++;
        if (end > start) res.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
        else res.push_back(to_string(nums[start]));
        i = end+1;
    }
    return res;
}

Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"


class Solution {
public:
    string simplifyPath(string path) {
        string res, t;
        stringstream ss(path);
        vector<string> v;
        while (getline(ss, t, '/')) {
            if (t == "" || t == ".") continue;
            if (t == ".." && !v.empty()) v.pop_back();
            else if (t != "..") v.push_back(t);
        }
        for (string s : v) res += "/" + s;
        return res.empty() ? "/" : res;
    }
};
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        char *cstr = new char[path.length() + 1];
        strcpy(cstr, path.c_str());
        char *pch = strtok(cstr, "/");
        while (pch != NULL) {
            string p = string(pch);
            if (p == "..") {
                if (!v.empty()) v.pop_back();
            } else if (p != ".") {
                v.push_back(p);
            }
            pch = strtok(NULL, "/");
        }
        if (v.empty()) return "/";
        string res;
        for (int i = 0; i < v.size(); ++i) {
            res += '/' + v[i];
        }
        return res;
    }
};

class Solution {
public:
    int search(int A[], int n, int target) {
        if (n == 0) return -1;
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (A[mid] == target) return mid;
            else if (A[mid] < A[right]) {
                if (A[mid] < target && A[right] >= target) left = mid + 1;
                else right = mid - 1;
            } else {
                if (A[left] <= target && A[mid] > target) right = mid - 1;
                else left = mid + 1;
            }
        }
        return -1;
    }
};

Wildcard Matching

class Solution {
public:
    bool isMatch(string s, string p) {
        int ssize = (int) s.size();
        int psize = (int) p.size();
        int i=0,j=0,si=0,sj=psize;
        while(i<ssize){
            if(s[i]==p[j]||p[j]=='?'){
                i++;
                j++;
            } else if(p[j]=='*'){
                sj = j++;
                si = i;
            } else if(sj<psize){
                j = sj+1 ;
                i = ++si;
            } else
                return false;
        }
       while(p[j]=='*'){
           j++;
       }
       return j==psize;
   }  
};

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            if (p[i - 1] == '*') dp[0][i] = dp[0][i - 1];
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};


Regular match 

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty())  
            return s.empty();
        if (p[1] != '*') {
            return !s.empty() && (p[0] == s[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1)); 
        }else {
            return isMatch(s, p.substr(2)) || !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p);
        }
    }
};

1.  P[i][j] = P[i - 1][j - 1],
 if p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
2.  P[i][j] = P[i][j - 2], 
if p[j - 1] == '*' and the pattern repeats for 0 times;
3.  P[i][j] = P[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'), 
if p[j - 1] == '*' and the pattern repeats for at least 1 times.


class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (j > 1 && p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                } else {
                    dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return dp[m][n];
    }
};


[LeetCode] Construct Binary Tree from String 
 

You need to construct a binary tree from a string consisting of parenthesis and integers.

The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the 
root value and a pair of parenthesis contains a child binary tree with the same structure.

You always start to construct the left child node of the parent first if it exists.

Example:

Input: "4(2(3)(1))(6(5))"
Output: return the tree root node representing the following tree:

       4
     /   \
    2     6
   / \   / 
  3   1 5 

class Solution {
public:
    TreeNode* str2tree(string s) {
        if (s.empty())
            return NULL:
        stack<TreeNode*> st;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ')') st.pop();
            else if ((s[i] >= '0' && s[i] <= '9') || s[i] == '-') {
                int j = i;
                while (i + 1 < s.size() && s[i + 1] >= '0' && s[i + 1] <= '9') ++i;
                TreeNode *cur = new TreeNode(stoi(s.substr(j, i - j + 1)));
                if (!st.empty()) {
                    TreeNode *t = st.top();
                    if (!t->left) t->left = cur;
                    else t->right = cur;
                }
                st.push(cur);
            }
        }
        return st.top();
    }
};


class Solution {
public:
    string tree2str(TreeNode* t) {
        if (!t) return "";
        string res = to_string(t->val);
        if (!t->left && !t->right)
            return res;
        res += "(" + tree2str(t->left) +")";
        if (t->right) res += "(" + tree2str(t->right) + ")";
        return res;
    }
};
