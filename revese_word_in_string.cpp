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

/*
[LeetCode] Reverse Words in a String II

Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.
The input string does not contain leading or trailing spaces and the words are always separated by a single space.
For example,
Given s = "the sky is blue",
return "blue is sky the".
Could you do it in-place without allocating extra space?

*/
class Solution {
public:
    void reverseWords(string &s) {
        int left = 0;
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') {
                reverse(s, left, i - 1);
                left = i + 1;
            }
        }
        reverse(s, 0, s.size() - 1);
    }
    void reverse(string &s, int left, int right) {
        while (left < right) {
           swap(s[left++], s[right--]);
        }
    }
};
