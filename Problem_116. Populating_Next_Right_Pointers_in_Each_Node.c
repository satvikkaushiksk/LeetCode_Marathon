/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

struct Node* connect(struct Node* root) {
    if (root == NULL)
        return NULL;
    struct Node* left = root;
    while (left->left != NULL) {
        struct Node* current = left;
        while (current != NULL) {
            current->left->next = current->right;
            if (current->next != NULL)
                current->right->next = current->next->left;
            current = current->next;
        }
        left = left->left;
    }
    return root;
}