/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* ans = malloc(100 * sizeof(int));
    *returnSize = 0;
    void inorder(struct TreeNode* root) {
        if (root == NULL)
            return;
        inorder(root->left);
        ans[(*returnSize)++] = root->val;
        inorder(root->right);
    }
    inorder(root);
    return ans;
}