
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> res;
        int cnt = 0;
        vector<int> roots(m * n, -1);
        vector<vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        for (auto a : positions) {
            int id = n * a.first + a.second;
            if (roots[id] == -1) {
                roots[id] = id;
                ++cnt;
            }
            for (auto dir : dirs) {
                int x = a.first + dir[0], y = a.second + dir[1], cur_id = n * x + y;
                if (x < 0 || x >= m || y < 0 || y >= n || roots[cur_id] == -1) continue;
                int p = findRoot(roots, cur_id), q = findRoot(roots, id);
                if (p != q) {
                    roots[p] = q;
                    --cnt;
                }
            }
            res.push_back(cnt);
        }
        return res;
    }
    int findRoot(vector<int>& roots, int id) {
        return (id == roots[id]) ? id : findRoot(roots, roots[id]);
    }
};

[LeetCode] Number of Islands II 岛屿的数量之二
 

A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which turns the water at position (row, col) into a land. Given a list of positions to operate, count the number of islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example:

Given m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]].
Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).

0 0 0
0 0 0
0 0 0
Given a reference to the head of a doubly-linked list and an integer, , create a new DoublyLinkedListNode object having data value  and insert it into a sorted linked list while maintaining the sort.

Function Description

Complete the sortedInsert function in the editor below. It must return a reference to the head of your modified DoublyLinkedList.

sortedInsert has two parameters:

head: A reference to the head of a doubly-linked list of DoublyLinkedListNode objects.
data: An integer denoting the value of the  field for the DoublyLinkedListNode you must insert into the list.

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
        DoublyLinkedListNode *dummy = new DoublyLinkedListNode(-1);
        dummy->next = head;
        DoublyLinkedListNode *prev = dummy;
        while (prev->next != NULL && prev->next->data < data) {
            prev = prev->next;
        }
        DoublyLinkedListNode *node = new DoublyLinkedListNode(data);
        node->next = prev->next;
        if (prev->next != NULL) {
            prev->next->prev = node;
        }
        node->prev = prev;
        prev->next = node;
        return dummy->next;
}
DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
    if (head == NULL){
        return NULL;
    }
    DoublyLinkedListNode *cur = head;
    while (cur != NULL) {
        DoublyLinkedListNode *node = cur->prev;
        cur->prev = cur->next;
        cur->next = node;
        if (cur ->prev == NULL)
            return cur;
        cur = cur->prev;
    }
    return cur;
}
