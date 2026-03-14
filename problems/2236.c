bool checkTree(struct TreeNode* root) {
    return ((root->left->val + root->right->val) == root->val);
}