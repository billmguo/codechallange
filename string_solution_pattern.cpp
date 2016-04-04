e two pointers: start and end to represent a window.
2. Move end to find a valid window.
3. When a valid window is found, move start to find a smaller window.
To check if a window is valid, we use a map to store (char, count) for chars in t. And use counter for the number of chars of t to be found in s. The key part is m[s[end]]--;. We decrease count for each char in s. If it does not exist in t, the count will be negative.

To really understand this algorithm, please see my code which is much clearer, because there is no code like if(map[s[end++]]++>0) counter++;.

string minWindow(string s, string t) {
    unordered_map<char, int> m;
    // Statistic for count of char in t
    for (auto c : t) m[c]++;
    // counter represents the number of chars of t to be found in s.
    size_t start = 0, end = 0, counter = t.size(), minStart = 0, minLen = INT_MAX;
    size_t size = s.size();

    // Move end to find a valid window.
    while (end < size) {
        // If char in s exists in t, decrease counter
        if (m[s[end]] > 0)
            counter--;
        // Decrease m[s[end]]. If char does not exist in t, m[s[end]] will be negative.
        m[s[end]]--;
        end++;
        // When we found a valid window, move start to find smaller window.
        while (counter == 0) {
            if (end - start < minLen) {
                minStart = start;
                minLen = end - start;
            }
            m[s[start]]++;
            // When char exists in t, increase counter.
            if (m[s[start]] > 0)
                counter++;
            start++;
        }
    }
    if (minLen != INT_MAX)
        return s.substr(minStart, minLen);
    return "";
}
