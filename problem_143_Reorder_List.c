/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {
    if (!head || !head->next)
        return;
    struct ListNode *p = head, *q = head;
    while (q->next->next)
        q = q->next;
    struct ListNode *last = q->next;
    q->next = NULL;
    last->next = p->next;
    p->next = last;
    reorderList(last->next);
}