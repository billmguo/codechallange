LeetCode 422. Valid Word Square

Given a sequence of words, check whether it forms a valid word square.

A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 ≤ k < max(numRows, numColumns).

Note:

The number of words given is at least 1 and does not exceed 500.
Word length will be at least 1 and does not exceed 500.
Each word contains only lowercase English alphabet a-z.
Example 1:

Input:
[
  "abcd",
  "bnrt",
  "crmy",
  "dtye"
]

Output:
true

Explanation:
The first row and first column both read "abcd".
The second row and second column both read "bnrt".
The third row and third column both read "crmy".
The fourth row and fourth column both read "dtye".

Therefore, it is a valid word square.

#include <iostream>
#include <vector>
using namespace std;

bool validwordsquare(vector<string> &words){
	if (words.size() == 0)
		return true;
	int m = words.size();
	int n = words[0].size();
	if ( m!= n)
		return false;
	for (int i = 0; i < m ; i++){
		string can = words[i];
		string res ="";
		for (int j = 0; j < m;j++)
			res += words[j][i];
		if (res != can)
			return false;
	}
	return true;
}
int main() {
	vector<string> words{"abcd","bnrt", "crmy","dtye"};
	bool flg = validwordsquare(words);
	cout<<flg<<endl;
	// your code goes here
	return 0;
}
