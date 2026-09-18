#include <stddef.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode* node = head;
    int count = 0;
    while (node != NULL && count < k) {
        node = node->next;
        count++;
    }
    if (count < k) {
        return head;
    }
    struct ListNode* prev = NULL;
    struct ListNode* temp = head;
    for (int i = 0; i < k; i++) {
        struct ListNode* next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    head->next = reverseKGroup(temp, k);
    return prev;
}