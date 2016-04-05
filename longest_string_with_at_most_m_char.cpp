/*longest subsring with M distinct*/
int lengthOfLongestSubstringTwoDistinct(string s, int m) {
    if (s.size()==0 || m==0)
        return 0;
    const int size_s = s.size();
    unordered_map<char, int> cand;
    int idx_start = 0, long_len = 0;
    for (int i = 0; i < size_s; i++) {
        cand[s[i]]++;
        while(cand.size() > m){
            if (--cand[idx_start] == 0) cand.erase(s[idx_start]);
            idx_start++;
        }
        long_len = max(long_len, i - idx_start + 1);
    }
    return long_len;
}
