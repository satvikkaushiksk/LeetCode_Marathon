/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    int a[100000], i = 0;
    while (head != NULL) {
        a[i++] = head->val;
        head = head->next;
    }
    for (int j = 0; j < i / 2; j++) {
        if (a[j] != a[i - j - 1])
            return false;
    }
    return true;
}

