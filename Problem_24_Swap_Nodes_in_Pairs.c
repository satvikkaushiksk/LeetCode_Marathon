#include <stddef.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* newHead = head->next;
    struct ListNode* prev = NULL;
    struct ListNode* first = head;

    while (first != NULL && first->next != NULL) {
        struct ListNode* second = first->next;

        first->next = second->next;
        second->next = first;

            if (prev != NULL) {
            prev->next = second;
        }

        prev = first;      
        first = first->next;
    }

    return newHead;
}