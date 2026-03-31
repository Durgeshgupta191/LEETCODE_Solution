class Solution {
public:
    TreeNode* nextRight = NULL;  // Pointer to track the next node in flattened list

    void flatten(TreeNode* root) {
        if (root == NULL) {
            return;  // Base case: empty subtree
        }

        // Recursively flatten right subtree first
        flatten(root->right);

        // Then recursively flatten left subtree
        flatten(root->left);

        // Set current node's left to NULL (since we're converting to right-skewed list)
        root->left = NULL;

        // Point current node's right to the previously visited node (next in list)
        root->right = nextRight;

        // Move the 'nextRight' pointer to current node for the next recursive call
        nextRight = root;
    }
};
