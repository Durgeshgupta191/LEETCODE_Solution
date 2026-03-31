//104. Maximum Depth of Binary Tree

int maxDepth(TreeNode* root) {
    // Base case: if the tree is empty, depth is 0
    if(root == NULL)
        return 0;

    // Recursively find the depth of the left subtree
    int left = maxDepth(root->left);

    // Recursively find the depth of the right subtree
    int right = maxDepth(root->right);

    // Return the larger depth between left and right + 1 (for the current node)
    return 1 + max(left, right);
}