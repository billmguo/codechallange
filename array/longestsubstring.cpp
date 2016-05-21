/*
最长合成字符串

题目描述

有一组单词，请编写一个程序，在数组中找出由数组中字符串组成的最长的串A，即A是由其它单词组成的(可重复)最长的单词。

给定一个string数组str，同时给定数组的大小n。请返回最长单词的长度，保证题意所述的最长单词存在。

测试样例：
["a","b","c","ab","bc","abc"],6
返回：3
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
class LongestString {
public:
    bool canBuild(string &s, bool isOriginalWord, map<string, bool> &mp) {
        if (mp.count(s) && !isOriginalWord) 
        	return mp[s];
        for (int i = 1; i < s.length(); ++i) {
            string left = s.substr(0, i);
            string right = s.substr(i);
            if (mp.count(left) && canBuild(right, false, mp)) {
                return true;
            }
        }
        mp[s] = false;
        return false;
    }
    int getLongest(vector<string> str) {
        // write code here
        map<string, bool> mp;
        for (auto &s : str) mp[s] = true;
        sort(str.begin(), str.end(), [](const string &a, const string &b) {
            return a.length() > b.length();
        });
        for (auto &s : str) {
            if (canBuild(s, true, mp)) return s.length();
        }
        return 0;
    }
};

int main() {
	// your code goes here
	LongestString sl;
	vector<string> s{"a","b","c","ab","bc","abc","aaaaaa"};
	int res = sl.getLongest(s);
	cout<<res<<endl;
	return 0;
}
