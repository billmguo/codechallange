/*://www.hackerrank.com/domains/algorithms/strings*/
/*Given a string, SS, we define some operations on the string as follows:

a. reverse(S) denotes the string obtained by reversing string SS. E.g.: reverse("abc") = "cba"

b. shuffle(S) denotes any string that's a permutation of string SS. E.g.: shuffle("god") ∈ ['god', 'gdo', 'ogd', 'odg', 'dgo', 'dog']

c. merge(S1,S2) denotes any string that's obtained by interspersing the two strings S1S1 & S2S2, maintaining the order of characters in both. 
E.g.: S1 = "abc" & S2 = "def", one possible result of merge(S1,S2) could be "abcdef", another could be "abdecf", another could be "adbecf" and so on.

Given a string SS such that S∈S∈ merge(reverse(A), shuffle(A)), for some string AA, can you find the lexicographically smallest AA?*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    string s;
    cin >> s;
    map<char,int> count;
    map<char,int> need;

    for (auto a:s){
        count[a]++;
    }
    for (auto m:count){
        need[m.first] = m.second/2;
    }

    string res;
    int i = 0;
    char c;
    while(res.size() < s.size()/2) {
        int min_pos = -1;
        while(true) {
            c = s[i];
            if (need[c] > 0 && (min_pos == -1 || c < s[min_pos]))
                min_pos = i;
            count[c]--;
            if (count[c] < need[c])
                break;
            i++;
        }
        for (int j = min_pos + 1; j < i;j++)
            count[c]++;

        need[s[min_pos]] --;	
        res.push_back(s[min_pos]);
        i = min_pos + 1;
    }

    cout<<res<<endl;
    return 0;
}

