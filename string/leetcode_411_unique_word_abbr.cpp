
/* 411. Minimum Unique Word Abbreviation

A string such as "word" contains the following abbreviations:

["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
Given a target string and a set of strings in a dictionary, find an abbreviation of this target string with the smallest possible length such that it does not conflict with abbreviations of the strings in the dictionary.

Each number or letter in the abbreviation is considered length = 1. For example, the abbreviation "a32bc" has length = 4.

Note:

In the case of multiple answers as shown in the second example below, you may return any one of them.
Assume length of target string = m, and dictionary size = n. You may assume that m ≤ 21, n ≤ 1000, and log2(n) + m ≤ 20.

Examples:

"apple", ["blade"] -> "a4" (because "5" or "4e" conflicts with "blade")

"apple", ["plain", "amber", "blade"] -> "1p3" (other valid answers include "ap3", "a3e", "2p2", "3le", "3l1").*/

#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;
 
class Solution {
    int n, cand, bn, minlen, minab;
    vector<int> dict;
public:   
    // Return the length of abbreviation given bit sequence
   int abbrLen2(int mask) {
        int count = 0;
        for (int b = 1; b < bn; b <<= 1) {
            if ((mask & b) == 0)
               continue;
            count++;
        }
        return count ;
    }
    int abbrLen(int mask) {
        int count = 0;
        for (int b = 1; b < bn;) {
            if ((mask & b) == 0)
                for (; b < bn and (mask & b) == 0; b <<= 1);
            else b <<= 1;
            count ++;
        }
        return count;
    }
 
    // DFS backtracking
    void dfs(int bit, int mask) {
        int len = abbrLen(mask);
        if (len >= minlen) return;
        bool match = true;
        for (auto d : dict) {
            if ((mask & d) == 0) {
                match = false;
                break;
            }
        }
        if (match) {
            minlen = len;
            minab = mask;
        }
        else
            for (int b = bit; b < bn; b <<= 1)
                if (cand & b) dfs(b << 1, mask + b);
    }
 
 
    string minAbbreviation(string target, vector<string>& dictionary) {
        n = target.size(), bn = 1 << n, cand = 0, minlen = INT_MAX;
        string res;
       
        // Preprocessing with bit manipulation
        for (auto w : dictionary) {
            int word = 0;
            if (w.size() != target.size()) continue;
            for (int i = 0, bit = 1; i < n;  i++, bit <<= 1)
                if (target[i] != w[i]) word += bit;
            dict.push_back(word);
            cand |= word;
        }
       
        dfs(1, 0);
        // Reconstruct abbreviation from bit sequence
       
        int cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (minab & 1) {
                if (cnt > 0){
                              res = to_string(cnt) + res;
                              cnt = 0;
                }
                res = target[i] + res;
            }
            else {
               cnt++;
            }
            minab >>= 1;
        }
        if (cnt)
               res = to_string(cnt) + res;
        return res;
    }
};
int main() {
               // your code goes here
               Solution sl;
               string target ="apple";
               vector<string> dict{"plain", "amber", "blade"};
               string res = sl.minAbbreviation(target, dict);
               cout<<res<<endl;
               return 0;
}
 
 
