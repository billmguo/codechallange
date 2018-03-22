DoublyListNode* bstToDoublyList(TreeNode* root) {  
        if (root == null) {
            return null;
        }
        //Init stack
        Stack<TreeNode*> st;
        TreeNode *node = root;    
        stack.push(node);
        //Create DoublyListNode header
        DoublyListNode *dummy = new DoublyListNode(0);
        DoublyListNode *dNode = dummy;
        
      
        while(node && !st.empty()) {
        	while (node != NULL && node->left != NULL) {
        		st.push(node->left);
        		node = node->left;
        	}
           	
            node = st.top();
            st.pop()
            DoublyListNode cur = new DoublyListNode(node->val);
            dNode->next = cur;
            cur->prev = dNode;
            dNode = dNode->next;

            //check right node and add to stack

            node = node->right;
            if (node != null) {
                stack.push(node);
            }  
        }
        return dummy.next;
    }

void BindarytoDoubleLinkedList(node *root, node *&head) {
	if (root == NULL)
		return;
	static node* prev = NULL;
	BindarytoDoubleLinkedList(root->left, head);
	if (prev == NULL)
		head = root;
	else{
		root->left = prev;
		prev->right = root;
	}
	prev = root;
	BindarytoDoubleLinkedList(root->right, head);
}


DlistNode *bsttolst(TreeNode* node) {
    if (root == NULL)
        return NULL;
        //Init stack
    stack<TreeNode*> st;
    TreeNode *p = root;
        //Create DoublyListNode header
    DListNode *head = NULL;
    DListNode *cur = head;
    while(node && !st.empty()) {
        while (node != NULL) {
            st.push(node);
            node = node->left;
        }
        node = st.top();
        st.pop()
        DLinkList *newnode = new LinkList(node->val);
        if (head == NULL){
            head = newnode;
        }else{
            cur->next = newnode;
            newnode->prev = cur;
            cur = cur->next;
        }
    }
    cur->next = head;
    head->next = cur;
    return head;
}


listNode *bsttolst(TreeNode* node) {
    if (root == NULL)
        return NULL;
        //Init stack
    stack<TreeNode*> st;
    TreeNode *p = root;
        //Create DoublyListNode header
    ListNode *head = NULL;
    ListNode *cur = head;
    while(node && !st.empty()) {
        while (node != NULL) {
            st.push(node);
            node = node->left;
        }
        node = st.top();
        st.pop()
        LinkList *newnode = new LinkList(node->val);
        if (head == NULL)
            head = newnode;
        else{
            cur->next = newnode;
            cur = cur->next;
        }
    }
    return head;
}
