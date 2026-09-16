#include <stddef.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode *fast = &dummy;
    struct ListNode *slow = &dummy;

    int i = 0;
    while (i <= n) {
        fast = fast->next;
        i++;
    }

    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    struct ListNode *toDelete = slow->next;
    slow->next = slow->next->next;
    free(toDelete);

    return dummy.next;
}