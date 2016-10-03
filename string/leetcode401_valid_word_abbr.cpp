/*
Given a non-empty string s and an abbreviation abbr, return whether the string matches with the given abbreviation.

A string such as "word" contains only the following valid abbreviations:

["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
Notice that only the above abbreviations are valid abbreviations of the string "word". Any other string is not a valid abbreviation of "word".

Note:
Assume s contains only lowercase letters and abbr contains only lowercase letters and digits.

Example 1:

Given s = "internationalization", abbr = "i12iz4n":

Return true.
Example 2:

Given s = "apple", abbr = "a2e":

Return false.
*/

#include <iostream>
#include <string>
using namespace std;

bool validWordAbbreviation(string &word, string &abbr){
	int len = abbr.size();
	int cnt = 0,  pos = 0;
	int wlen = word.size();
	for (int i = 0; i < len; i++) {
		if (isdigit(abbr[i])){
			cnt  = 10 * cnt + abbr[i] - '0';
			continue;
		}else{
			pos += cnt;
			cnt = 0;
			if (pos >= wlen || word[pos] != abbr[i])
				return false;
			pos++;
		}	
	}
	if ( pos + cnt == wlen)
		return true;
	else 
		return false;
}
int main() {
	// your code goes here
	string word ="internationalization";
	string abbr = "i12iz4n";
	bool res = validWordAbbreviation(word,abbr);
	cout<<res<<endl;
	string word1="apple";
	string abbr1 ="a2e";
	res = validWordAbbreviation(word1,abbr1);
	cout<<res<<endl;
	return 0;
}
