bool isUnivalTree(struct TreeNode *root)
{
    if (root == NULL)
        return true;

    if ((root->left  && root->left->val  != root->val) ||
        (root->right && root->right->val != root->val))
        return false;

    return isUnivalTree(root->left) && isUnivalTree(root->right);
}