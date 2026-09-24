/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode *sorted = NULL;
    while (head != NULL) {
        struct ListNode *node = head;
        head = head->next;
        if (sorted == NULL || node->val < sorted->val) {
            node->next = sorted;
            sorted = node;
        } 
        else {
            struct ListNode *temp = sorted;
            while (temp->next != NULL && temp->next->val < node->val)
                temp = temp->next;
            node->next = temp->next;
            temp->next = node;
        }
    }
    return sorted;
}