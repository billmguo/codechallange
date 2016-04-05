ven a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.

Examples:

pattern = "abab", str = "redblueredblue" should return true.
pattern = "aaaa", str = "asdasdasdasd" should return true.
pattern = "aabb", str = "xyzabcxzyabc" should return false. 
Notes:
You may assume both pattern and str contains only lowercase letters.


We can solve this problem using backtracking, we just have to keep trying to use a character in
 the pattern to match different length of substrings in the input string, 
 keep trying till we go through the input string and the pattern.

For example, input string is "redblueredblue", and the pattern is "abab", first
 let's use 'a' to match "r", 'b' to match "e", then we find that 'a' does not match "d", 
 so we do backtracking, use 'b' to match "ed", so on and so forth ...

When we do the recursion, if the pattern character exists in the hash map already, we just
 have to see if we can use it to match the same length of the string. For example, let's say we have the following map:

'a': "red"

'b': "blue"

now when we see 'a' again, we know that it should match "red", the length is 3, then let's see if str[i ... i+3]
 matches 'a', where i is the current index of the input string. Thanks to StefanPochmann's suggestion, in Java we c
 an elegantly use str.startsWith(s, i) to do the check.

Also thanks to i-tikhonov's suggestion, we can use a hash set to avoid duplicate matches, if character a matches 
string "red", then character b cannot be used to match "red". In my opinion though, we can say apple (pattern 'a') 
is "fruit", orange (pattern 'o') is "fruit", so they can match the same string, anyhow, I guess it really depends 
on how the problem states.
*/
class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        unordered_set<string> st;
        unordered_map<char, string> mp;
        return match(str, 0, pattern, 0, st, mp);
    }
private:
    bool match(string& str, int i, string& pat, int j, unordered_set<string>& st, unordered_map<char, string>& mp) {
        int m = str.length(), n = pat.length();
        if (i == m && j == n) return true;
        if (i == m || j == n) return false;
        char c = pat[j];
        if (mp.find(c) != mp.end()) {
            string s = mp[c];
            int l = s.length();
            if (s != str.substr(i, l)) return false;
            return match(str, i + l, pat, j + 1, st, mp);
        } 
        for (int k = i; k < m; k++) {
            string s = str.substr(i, k - i + 1);
            //if (st.find(s) != st.end()) continue;
           // st.insert(s);
            mp[c] = s;
            if (match(str, k + 1, pat, j + 1, st, mp)) return true;
           // st.erase(s);
            mp.erase(c);
        }
        return false;
    }
};
