#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <algorithm>
 
using namespace std;
struct TreeNode {
    char c; // character in an alphabet
    int cfreq; // frequency of c.
    TreeNode *left;
    TreeNode *right;
    TreeNode(char c, int cfreq, struct TreeNode *left=NULL,
                struct TreeNode *right=NULL) :
        c(c), cfreq(cfreq), left(left), right(right) {
    }
    ~TreeNode() {
        delete left; 
        delete right;
    }
    // Compare two tree nodes
    class Compare {
	    public:
	        bool operator()(TreeNode *a, TreeNode *b) {
	            return a->cfreq > b->cfreq;
	        }
    };
};

void traverse(TreeNode *root,string code, unordered_map<char, string> &mc) {
	if (root == NULL)
		return;
		
	if (root->left == NULL && root->right == NULL && root->c !=' '){
		mc[root->c] = code;
	}
	if (root->left)
		traverse(root->left, code +'0',mc);
	if (root->right)
		traverse(root->right, code + '1', mc);
}

int main() {
	string str = "abcdef";
	int cnt;
	priority_queue<TreeNode*,vector<TreeNode*>,TreeNode::Compare> pq;
	
	unordered_map<char,int> m;
	for (auto ch:str) {
		m[ch]++;
	}
	for (auto a:m) {
		TreeNode *newnode = new TreeNode(a.first,a.second);
		pq.push(newnode);
	}
	TreeNode *root = NULL;
	while(pq.size() > 1) {
		TreeNode *l = pq.top();
		pq.pop();
		TreeNode *r = pq.top();
		pq.pop();
		root = new TreeNode(' ',l->cfreq + r->cfreq,l,r);
		pq.push(root);
	}
	unordered_map<char, string> mc;
	string code="";
	traverse(root,code,mc);
	for (auto a:mc)
		cout << a.first << " " << a.second<<endl;
	return 0;
}
