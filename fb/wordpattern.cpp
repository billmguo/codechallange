class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        if (pattern.empty()) return str.empty();
        if (m.count(pattern[0])) {
            string t = m[pattern[0]];
            if (t.size() > str.size() || str.substr(0, t.size()) != t) return false;
            if (wordPatternMatch(pattern.substr(1), str.substr(t.size()))) return true;
        } else {
            for (int i = 1; i <= str.size(); ++i) {
                if (s.count(str.substr(0, i))) continue;
                m[pattern[0]] = str.substr(0, i);
                s.insert(str.substr(0, i));
                if (wordPatternMatch(pattern.substr(1), str.substr(i))) return true;
                m.erase(pattern[0]);
                s.erase(str.substr(0, i));
            }
        }
        return false;
    }
    unordered_map<char, string> m;
    unordered_set<string> s;
};

/*Stirng mulitply*/
class Solution {
public:
    string multiply(string num1, string num2) {
        string res;
        int n1 = num1.size(), n2 = num2.size();
        int k = n1 + n2 - 2, carry = 0;
        vector<int> v(n1 + n2, 0);
        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < n2; ++j) {
                v[k - i - j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        for (int i = 0; i < n1 + n2; ++i) {
            v[i] += carry;
            carry = v[i] / 10;
            v[i] %= 10;
        }
        
        int i = n1 + n2 - 1;
        while (v[i] == 0) 
            i--;
        if (i < 0)
            return "0";
        while (i >= 0)
            res.push_back(v[i--] +'0');
        return res;
    }
};
