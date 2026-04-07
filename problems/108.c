#include <stdlib.h>
#include <stdio.h>

/**
 * Definition for a binary tree node.
 */
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

/**
 * Recursively builds a height-balanced BST from a sorted subarray.
 *
 * @param nums  Sorted integer array
 * @param left  Left boundary index (inclusive)
 * @param right Right boundary index (inclusive)
 * @return      Root of the constructed subtree, or NULL
 */
static TreeNode *buildBST(const int *nums, int left, int right)
{
    if (left > right)
        return NULL;

    /* Avoids potential overflow vs. (left + right) / 2 */
    int mid = left + (right - left) / 2;

    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    if (!node) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    node->val   = nums[mid];
    node->left  = buildBST(nums, left, mid - 1);
    node->right = buildBST(nums, mid + 1, right);

    return node;
}

/**
 * Converts a sorted array into a height-balanced binary search tree.
 *
 * @param nums     Sorted integer array
 * @param numsSize Number of elements in nums
 * @return         Root of the balanced BST, or NULL if input is empty/invalid
 */
TreeNode *sortedArrayToBST(const int *nums, int numsSize)
{
    if (!nums || numsSize <= 0)
        return NULL;

    return buildBST(nums, 0, numsSize - 1);
}

/**
 * Frees all nodes in the BST to prevent memory leaks.
 *
 * @param root Root of the BST to free
 */
void freeBST(TreeNode *root)
{
    if (!root)
        return;

    freeBST(root->left);
    freeBST(root->right);
    free(root);
}

/**
 * Prints the BST using in-order traversal (should output sorted values).
 *
 * @param root Root of the BST
 */
void inorderPrint(const TreeNode *root)
{
    if (!root)
        return;

    inorderPrint(root->left);
    printf("%d ", root->val);
    inorderPrint(root->right);
}