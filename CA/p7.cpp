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
