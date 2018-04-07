class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        if (s1.size() != s2.size()) return false;
        int n = s1.size(), m[26] = {0};
        for (int i = 0; i < n; ++i) {
            ++m[s1[i] - 'a'];
            --m[s2[i] - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (m[i] != 0) return false;
        }
        for (int i = 1; i < n; ++i) {
            if ((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) || (isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i), s2.substr(0, n - i)))) {
                return true;
            }
        }
        return false;
    }
};


Sorted list to binary tree 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (!head) return NULL;
        if (!head->next) return new TreeNode(head->val);
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *last = slow;
        while (fast->next && fast->next->next) {
            last = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        last->next = NULL;
        TreeNode *cur = new TreeNode(slow->val);
        if (head != slow) cur->left = sortedListToBST(head);
        cur->right = sortedListToBST(fast);
        return cur;
    }
};
