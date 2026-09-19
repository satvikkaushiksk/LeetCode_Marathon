#include <stddef.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    while (head != NULL && head->next != NULL && head->val == head->next->val) {
        int dupVal = head->val;
        while (head != NULL && head->val == dupVal) {
            head = head->next;
        }
    }
    if (head == NULL) {
        return NULL;
    }
    struct ListNode* temp = head;
    while (temp->next != NULL && temp->next->next != NULL) {
        if (temp->next->val == temp->next->next->val) {
            int dupVal = temp->next->val;
            struct ListNode* runner = temp->next;
            while (runner != NULL && runner->val == dupVal) {
                runner = runner->next;
            }
            temp->next = runner;
        } else {
            temp = temp->next; 
        }
    }
    return head;
}