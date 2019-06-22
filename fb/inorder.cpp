Given a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree i
s now the root of the tree, and every node has no left child and only 1 right child.
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
    	TreeNode *head = new TreeNode(0), *pre = head;
    	stack<TreeNode*> st;
    	while(root || !st.empty()) {
    		while(root) {
    			st.push(root);
    			root = root->left;
    		}
    		root = st.top();
    		st.pop();
    		/*code change to link the node*/
    		prev->right = root;
    		prev = prev->right;
    		root->left = NULL;
    		/*end of the code*/
    		root = root->right
    	}
        return head->right;
    }
};

class Solution {
    TreeNode *prev = NULL, *head = NULL;
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(root==NULL) 
            return NULL;   
        increasingBST(root->left);  
        if(prev != NULL) { 
        	root->left = NULL; // we no  longer needs the left  side of the node, so set it to null
        	prev->right = root; 
        }
        if(head == NULL) 
            head=root; // record the most left node as it will be our root
        prev = root; //keep track of the prev node
        increasingBST(root->right); 
        return head;
    }
};
