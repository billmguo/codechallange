


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
