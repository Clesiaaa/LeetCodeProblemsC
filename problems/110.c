/* Returns -1 if unbalanced, otherwise returns the height.
   Single-pass O(n) — avoids redundant height recomputation. */
static int checkHeight(const struct TreeNode *node)
{
    if (node == NULL)
        return 0;

    int leftHeight = checkHeight(node->left);
    if (leftHeight == -1) return -1;          /* Propagate failure early */

    int rightHeight = checkHeight(node->right);
    if (rightHeight == -1) return -1;

    if (abs(leftHeight - rightHeight) > 1)
        return -1;                             /* Unbalanced at this node */

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

bool isBalanced(const struct TreeNode *root)
{
    return checkHeight(root) != -1;
}