class Solution {
public:
   int newInteger(int n) {
        int res = 0, base = 1;
        while (n > 0) {
            res += n % 9 * base;
            n /= 9;
            base *= 10;
        }
        return res;
   }
};
Maximum Size Subarray Sum Equals k
 int maxSubArrayLen(vector<int>& nums, int k) {
        int res = 0;
        int sum  = 0;
        unordered_map<int, int> m{{0,-1}};
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (m.count(sum - k)) {
                res = max(res, i - m[sum - k]);
            }
            if (!m.count(sum))
                m[sum] = i;
        }
        return res;
    }

if (n <= 8) return n;
return 10 * newInteger(n / 9) + (n % 9)

while (num!= 0 && cnt++ < 8) {
	res = str[(num & 0xf)] + res;
	num >>= 4;
}
return res.empty()? "0":res;


bool wordPattern(string pattern, string str) {
        unordered_map<char, int> m1;
        unordered_map<string, int> m2;
        istringstream in(str);
        int i = 0;
        for (string word; i >> word; i++) {
        	if (m1.count(pattern[i]) || m2.count(word))
        		if (m1[pattern[i]] != m2[word])
        			return false;
        	else{
        		m1[pattern[i]] = i + 1;
        		m2[word] = i + 1;
        	}

        }
        return i == pattern.size();
    }



 class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char, string> m;
        set<string> s;
        return helper(pattern, 0, str, 0, m, s);
    }
    bool helper(string pattern, int p, string str, int r, unordered_map<char, string> &m, set<string> &s) {
        if (p == pattern.size() && r == str.size()) return true;
        if (p == pattern.size() || r == str.size()) return false;
        char c = pattern[p];
        for (int i = r; i < str.size(); ++i) {
            string t = str.substr(r, i - r + 1);
            if (m.count(c) && m[c] == t) {
                if (helper(pattern, p + 1, str, i + 1, m, s)) return true;
            } else if (!m.count(c)) {
            	if (s.count(t))
            		continue;
            	if (s.count(t)) continue;
                m[c] = t;
                s.insert(t);
                if (helper(pattern, p + 1, str, i + 1, m, s)) return true;
                m.erase(c);
                s.erase(t);
            }
        }
        return false;
    }
};

Given m arrays, and each array is sorted in ascending order. Now you can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a-b|. Your task is to find the maximum distance.

Example 1:

Input: 
[[1,2,3],
 [4,5],
 [1,2,3]]

 Output: 4

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int res = 0, mins = arrays[0][0], maxe = arrays[0].back();
        for (int i = 1; i < arrays.size(); ++i) {
            res = max(res, max(abs(arrays[i].back() - mins), abs(maxe - arrays[i][0])));
            mins = min(mins, arrays[i][0]);
            maxe = max(maxe, arrays[i].back());
        }
        return res;
    }
};
