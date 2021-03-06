Game of life

[LeetCode] Game of Life 生命游戏

class Solution {
public:
    void gameOfLife(vector<vector<int> >& board) {
        int m = board.size(), n = m ? board[0].size() : 0;
        int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int cnt = 0;
                for (int k = 0; k < 8; ++k) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x >= 0 && x < m && y >= 0 && y < n && (board[x][y] == 1 || board[x][y] == 2)) {
                        ++cnt;
                    }
                }
                if (board[i][j] && (cnt < 2 || cnt > 3)) board[i][j] = 2;
                else if (!board[i][j] && cnt == 3) board[i][j] = 3;
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] %= 2;
            }
        }
    }
};

maxium increase in the tree
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        return helper(root, NULL, 0);
    }
    int helper(TreeNode *root, TreeNode *p, int res) {
        if (!root) return res;
        res = (p && root->val == p->val + 1) ? res + 1 : 1;
        return max(res, max(helper(root->left, root, res), helper(root->right, root, res)));
    }
};


[LeetCode] 90. Subsets II 子集合之二
 

Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
 

For example,
If S = [1,2,2], a solution is:

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
    vector<vector<int>> subsetsWithDup(vector<int> &S) {
        if (S.empty()) return {};
        vector<vector<int>> res;
        vector<int> out;
        sort(S.begin(), S.end());
        getSubsets(S, 0, out, res);
        return res;
    }
    void getSubsets(vector<int> &S, int pos, vector<int> &out, vector<vector<int>> &res) {
        res.push_back(out);
        for (int i = pos; i < S.size(); i++) {
        	out.push_back(S[i]);
        	getSubSets(S, i + 1, out, res);
        	out.pop_back();
        	while (i + 1 < S.size() && S[i] == S[i + 1])
        		i++;
        }
    }
};
/*

[LeetCode] Find the Derangement of An Array 找数组的错排
 

In combinatorial mathematics, a derangement is a permutation of the elements of a set, such that no element appears in its original position.

There's originally an array consisting of n integers from 1 to n in ascending order, you need to find the number of derangement it can generate.

Also, since the answer may be very large, you should return the output mod 109 + 7.

Example 1:

Input: 3
Output: 2
Explanation: The original array is [1,2,3]. The two derangements are [2,3,1] and [3,1,2].
*/

countDer(n) = (n - 1) * [countDer(n - 1) + countDer(n - 2)]

dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2])

for (int i = 3; i <=n; i++)
dp[i] = (dp[i-1] + dp[i-2]) * (i - 1)

class Solution {
public:
    int findDerangement(int n) {
        if (n < 2) return 0;
        vector<long long> dp(n + 1, 0);
        dp[1] = 0; dp[2] = 1;
        for (int i = 3; i <= n; ++i) {
            dp[i] = (dp[i - 1] + dp[i - 2]) * (i - 1) % 1000000007;
        }
        return dp[n];
    }
};
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> res;
        vector<string> dict{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        dfs(digits, dict, 0, "", res);
        return res;
    }
    void dfs(string& digits, vector<string>& dict, int level, string out, vector<string>& res) {
        if (level == digits.size()) 
           {res.push_back(out); return;}
        string str = dict[digits[level] - '0'];
        for (int i = 0; i < str.size(); ++i) {
            dfs(digits, dict, level + 1, out + str[i], res);
        }
    }
};

Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

class Solution {
public:
    void reverseWords(string &s) {
        istringstream is(s);
        string tmp;
        is >> s;
        while(is >> tmp) s = tmp + " " + s;
        if (!s.empty() && s[0] == ' ') s="";
    }
};

class Solution {
public:
    void reverseWords(string &s) {
        istringstream is(s);
        s = "";
        string t = "";
        while (getline(is, t, ' ')) {
        	if (t.empty()) continue;
        	s = (s.empty() ? t : (t + " " + s));
        }
    }
};



class Solution {
public:
    void reverseWords(string &s) {
        int sindex = 0, n = s.size();
        reverse(s.begin(), s.end());
        for (int i = 0; i < n; ++i) {
            if (s[i] != ' ') {
                if (sindex != 0)
                	s[sindex++] = ' ';
                int j = i;
                while (j < n && s[j] != ' ') 
                	s[sindex++] = s[j++];
                reverse(s.begin() + sindex - (j - i), s.begin() + sindex);
                i = j;
            }
        }
        s.resize(sindex);
    }
};


/*
lettcode] Reverse Words in a String 翻转字符串中的单词
 
Given an input string, reverse the string word by word.
For example,
Given s = "the sky is blue",
return "blue is sky the".
*/

class Solution {
public:
    void reverseWords(string &s) {
        int i = 0, j = 0, k = 0, wordCount = 0;
        while (true) {
            while (i < s.size() && s[i] == ' ') ++i;
            if (i == s.size()) break;
            if (wordCount) s[j++] = ' ';
            k = j;
            while (i < s.size() && s[i] != ' ') {
                s[j] = s[i];
                ++j; ++i;
            }
            reverseWord(s, k, j - 1);
            ++wordCount;
        }
        s.resize(j);
        reverseWord(s, 0, j - 1);
    }
    void reverseWord(string &s, int i, int j) {
        while (i < j) {
            swap(s[i++],s[j--]);
        }
    }
};
