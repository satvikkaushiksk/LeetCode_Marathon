#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
// This is the main logic behind the code// 
void deleteNode(struct ListNode* node) {
    node->val = node->next->val;
    struct ListNode* temp = node->next;
    node->next = node->next->next;
    free(temp);
}