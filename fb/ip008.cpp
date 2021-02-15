Given an array A of integers, return the length of the longest arithmetic subsequence in A.

Recall that a subsequence of A is a list A[i_1], A[i_2], ..., A[i_k] with 0 <= i_1 < i_2 < ... < i_k <= A.length - 1, 

and that a sequence B is arithmetic if B[i+1] - B[i] are all the same value (for 0 <= i < B.length - 1).


class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int res = 0, n = A.size();
        vector<vector<int>> dp(n, vector<int>(2000));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int diff = A[i] - A[j] + 1000;
                dp[i][diff] = dp[j][diff] + 1;
                res = max(res, dp[i][diff]);
            }
        }
        return res + 1;
    }
};

vector<

for (int i = 0; i < n; i++) {
	for (int j = 0; j < i; j++) {
		int diff = a[i] - A[j];
		dp[i][diff] = (dp[j][diff] + 1 )
		res = max(res, dp[i][diff])
	}
}

Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:

Input: S = "aab"
Output: "aba"
Example 2:

Input: S = "aaab"
Output: ""
Note:

class Solution {
public:
    string reorganizeString(string S) {
        string res = "";
        unordered_map<char, int> m;
        priority_queue<pair<int, char>> q;
        for (char c : S) ++m[c];
        for (auto a : m) {
            if (a.second > (S.size() + 1) / 2) return "";
            q.push({a.second, a.first});
        }

       

        while (q.size() >= 2) {
            auto t1 = q.top(); q.pop();
            auto t2 = q.top(); q.pop();
            res.push_back(t1.second);
            res.push_back(t2.second);
            if (--t1.first > 0) q.push(t1);
            if (--t2.first > 0) q.push(t2);
        }
        if (q.size() > 0) res.push_back(q.top().second);
        return res;
    }
};


class Solution {
public:
    string reorganizeString(string S) {
        priority_queue<pair<int, char>> pq;
        int map[26] = { 0 };
        
        for (auto c : S) {
            if (++map[c-'a'] > (S.size() + 1)/2)
                return "";
        }
        
        for (int i = 0; i < 26; ++i) {
            if (map[i])
                pq.push({map[i], i + 'a'});
        }
        
        string ans;
        while (!pq.empty()) {
        	auto t1 = pq.top(), pq.pop();
        	ans += t1.second;
        	if (!pq.empty()) {
        		auto t2 = pq.top(), pq.pop();
        		ans += t2.second;
        		if (--t2.first)
        			pq.push(t2);
        	}
        	if (--t1.first)
        		pq.push(t1);

        }
        return ans;
    }
};
