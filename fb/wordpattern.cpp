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
