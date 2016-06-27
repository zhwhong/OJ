/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    int left = maxDepth(root -> left);
    int right = maxDepth(root -> right);
    int depth = 1 + ((left>right) ? left : right);
    return depth;
}
