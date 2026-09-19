
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }
    struct ListNode* temp = head;
    while (temp->next != NULL) {
        if (temp->val == temp->next->val) {
            struct ListNode* dup = temp->next;
            temp->next = temp->next->next;
            free(dup);
        } else {
            temp = temp->next;
        }
    }
    return head;
}
 