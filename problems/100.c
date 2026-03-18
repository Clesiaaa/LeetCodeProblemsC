bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
   return (!p && !q) ? true : (!p || !q) ? false : (p->val == q->val ? isSameTree(p->left, q->left) && isSameTree(p->right, q->right) : false);
}