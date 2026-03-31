/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:

    // Helper function to check mirror
    bool isMirror(TreeNode* left, TreeNode* right) {

        // Case 1: both nodes are NULL
        if(left == NULL && right == NULL)
            return true;

        // Case 2: only one node is NULL
        if(left == NULL || right == NULL)
            return false;

        // Case 3: values must match and children must be mirror
        if(left->val == right->val)
            return isMirror(left->left, right->right) &&
                   isMirror(left->right, right->left);

        return false;
    }

    bool isSymmetric(TreeNode* root) {

        // Empty tree is symmetric
        if(root == NULL)
            return true;

        // Check if left and right subtree are mirror
        return isMirror(root->left, root->right);
    }
};