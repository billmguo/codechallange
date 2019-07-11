read4K

int read(char *buf, int sz) {
	int ck = sz/4K; n = sz%n;
	for (int i = 0; i < ck; i++) {
		int t = read4k(buf);
		if (t < 0)
			return i * 4K;
	}
	int start = ck * 4K;
	if (n == 0)
		return sz;
	for (int i = 0; i < n; i++) {
		if (readp == writep) {
			writep = read4K(lbuf);
			readp = 0;
			if (writep)
				return i + start;
		}else
			buf[start + i] = lbuf[readp++];
	}
	return sz;
}


class Solution {
public:
string numberToWords(int num) {
    if (num == 0)
        return "Zero";
    string res = int2s(num);
    return res.substr(1);
}
private:   
    vector<pair<int,string>> rep{{pow(10,9), " Billion"},{pow(10, 6)," Million"},{pow(10,3)," Thousand"},{pow(10,2)," Hundred"}};
    vector<string> tens{"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> digits{"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string int2s(int n) {
        for (int i = 0; i < rep.size(); i++) {
            if (n >= rep[i].first) {
                return int2s(n/rep[i].first) + rep[i].second + int2s(n%rep[i].first);
            }
        }
        if (n >= 20) {
            return " " + tens[n/10] + int2s(n%10);
        } else if (n >= 1)
            return " " + digits[n];
        else 
            return "";
    }
 }

 tapping rain water

 class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0, mx = 0, n = height.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            dp[i] = mx;
            mx = max(mx, height[i]);
        }
        mx = 0;
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = min(dp[i], mx);
            mx = max(mx, height[i]);
            if (dp[i] > height[i]) res += dp[i] - height[i];
        }
        return res;
    }
};

Decode string

Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

class Solution {
public:
    string decodeString(string s) {
        string t = "";
        stack<int> s_num;
        stack<string> s_str;
        int cnt = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                cnt = 10 * cnt + s[i] - '0';
            } else if (s[i] == '[') {
                s_num.push(cnt);
                s_str.push(t);
                cnt = 0; t.clear();
            } else if (s[i] == ']') {
                int k = s_num.top(); s_num.pop();
                for (int j = 0; j < k; ++j) 
                	s_str.top() += t;
                t = s_str.top();
                s_str.pop();
            } else {
                t += s[i];
            }
        }
        return s_str.empty() ? t : s_str.top();
    }
};

Candy

class Solution {
public:
    int candy(vector<int>& ratings) {
        int res = 0, n = ratings.size();
        vector<int> nums(n, 1);
        for (int i = 0; i < n - 1; ++i) {
            if (ratings[i + 1] > ratings[i])
             nums[i + 1] = nums[i] + 1;
        }
        for (int i = n - 1; i > 0; --i) {
            if (ratings[i - 1] > ratings[i])
            	nums[i - 1] = max(nums[i - 1], nums[i] + 1);
        }
        for (int num : nums)
           res += num;
        return res;
    }
};

Leetcode MergeInterval

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res{intervals[0]};
        for (int i = 1; i < intervals.size(); ++i) {
            if (res.back()[1] < intervals[i][0]) {
                res.push_back(intervals[i]);
            } else {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        }   
        return res;
    }
};

[LeetCode] Word Break II 拆分词句之二
 

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]

class Solution {
public:
    unordered_map<string, vector<string>> m;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (m.count(s)) return m[s];
        if (s.empty()) return {""};
        vector<string> res;
        for (string word : wordDict) {
            if (s.substr(0, word.size()) != word) continue;
            vector<string> rem = wordBreak(s.substr(word.size()), wordDict);
            for (string str : rem) {
                res.push_back(word + (str.empty() ? "" : " ") + str);
            }
        }
        return m[s] = res;
    }
};

[LeetCode] Spiral Matrix 螺旋矩阵

Given a matrix of m x n elements (m rows, ncolumns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        int up = 0, down = m - 1, left = 0, right = n - 1;
        while (true) {
            for (int j = left; j <= right; ++j) res.push_back(matrix[up][j]);
            if (++up > down) break;
            for (int i = up; i <= down; ++i) res.push_back(matrix[i][right]);
            if (--right < left) break;
            for (int j = right; j >= left; --j) res.push_back(matrix[down][j]);
            if (--down < up) break;
            for (int i = down; i >= up; --i) res.push_back(matrix[i][left]);
            if (++left > right) break;
        }
        return res;
    }
};

/*
[LeetCode] Permutation in String 字符串中的全排列
 

Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

Example 1:

Input:s1 = "ab" s2 = "eidbaooo"
Output:True
Explanation: s2 contains one permutation of s1 ("ba").

*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        vector<int> m1(128), m2(128);
        for (int i = 0; i < n1; ++i) {
            ++m1[s1[i]]; ++m2[s2[i]];
        }
        if (m1 == m2) return true;
        for (int i = n1; i < n2; ++i) {
            ++m2[s2[i]];
            --m2[s2[i - n1]];
            if (m1 == m2) return true;
        }
        return false;
    }
};

[LeetCode] 662. Maximum Width of Binary Tree 二叉树的最大宽度
 

Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

Example 1:


class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root, 1});
        while (!q.empty()) {
            int left = q.front().second, right = left, n = q.size();
            for (int i = 0; i < n; ++i) {
                auto t = q.front().first; 
                right = q.front().second; 
                q.pop();
                if (t->left)
                	q.push({t->left, right * 2});
                if (t->right)
                	q.push({t->right, right * 2 + 1});
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};
