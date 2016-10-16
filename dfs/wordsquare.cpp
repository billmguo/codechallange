LeetCode 425. Word Squares

Given a set of words (without duplicates), find all word squares you can build from them.

A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 ≤ k < max(numRows, numColumns).

For example, the word sequence ["ball","area","lead","lady"] forms a word square because each word reads the same both horizontally and vertically.

b a l l
a r e a
l e a d
l a d y
Note:

There are at least 1 and at most 1000 words.
All words will have the exact same length.
Word length is at least 1 and at most 5.
Each word contains only lowercase English alphabet a-z.
Example 1:

Input:
["area","lead","wall","lady","ball"]

Output:
[
  [ "wall",
    "area",
    "lead",
    "lady"
  ],
  [ "ball",
    "area",
    "lead",
    "lady"
  ]
]

Explanation:
The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
Example 2:

Input:
["abat","baba","atan","atal"]

Output:
[
  [ "baba",
    "abat",
    "baba",
    "atan"
  ],
  [ "baba",
    "abat",
    "baba",
    "atal"
  ]
]

Explanation:
The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).



#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:	
	vector<vector<string>> res;
	vector<string> vec;
 	struct TireNode{
 		vector<int> indexs;
 		vector<TireNode*> child;
 		TireNode(){
 			child.resize(26,nullptr);
 		}
 	};
 	TireNode *buildTire(vector<string> &words) {
 		TireNode *root = new TireNode();
 		for (int i = 0; i < words.size();i++) {
 			TireNode *t = root;
 			for (int j = 0; j < words[i].size();j++) {
 				if (!t->child[words[i][j] - 'a'])
 					t->child[words[i][j] - 'a'] = new TireNode();
 				t = t->child[words[i][j] -'a'];
 				t->indexs.push_back(i);
 			}
 		}
 		return root;
 	}
 	void dfs(vector<string>& words, int level, TireNode *root) {
 		if (level >= words[0].size()) {
 			res.push_back(vec);
 			return;
 		}
 		string str="";
 		for (auto &s:vec) 
 			str += s[level];
 		TireNode *t = root;
 		for (int i = 0; i < str.size();i++){
 			t = t -> child[str[i] -'a'];
 			if (!t) return;
 		}	
 		for (auto i:t->indexs) {
 			vec.push_back(words[i]);
 			dfs(words,level+1,root);
 			vec.pop_back();
 		}
 	}
 	vector<vector<string>> wordSquares(vector<string> &words) {
 		if (words.empty()) return res;
 		TireNode *root = buildTire(words);
 		for (auto a:words) {
 			vec.push_back(a);
 			dfs(words,1,root);
 			vec.pop_back();
 		}
 		return res;
 	}
};

int main() {
	// your code goes here
	Solution sl;
	vector<string> words{"area","lead","wall","lady","ball"};
	vector<vector<string>> res = sl.wordSquares(words);
	for (auto a:res){
		for(auto b:a)
			cout<<b<<endl;
	cout<<endl;		
	}
	return 0;
}
