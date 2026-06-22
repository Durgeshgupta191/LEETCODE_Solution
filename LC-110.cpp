class Solution {
public:

    // Function to calculate the height of a subtree.
    // Returns:
    // - Height of the subtree if it is balanced.
    // - -1 if the subtree is not balanced.
    int height(TreeNode* root) {

        // Base case: empty tree has height 0
        if (root == NULL) {
            return 0;
        }

        // Recursively calculate left subtree height
        int left = height(root->left);

        // If left subtree is unbalanced,
        // propagate -1 upward immediately
        if (left == -1) {
            return -1;
        }

        // Recursively calculate right subtree height
        int right = height(root->right);

        // If right subtree is unbalanced,
        // propagate -1 upward immediately
        if (right == -1) {
            return -1;
        }

        // Check whether current node is balanced
        // Difference between left and right heights
        // must not exceed 1
        if (abs(left - right) > 1) {
            return -1;
        }

        // Current node is balanced
        // Height = maximum child height + 1
        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {

        // If height() returns -1,
        // tree is unbalanced
        // Otherwise tree is balanced
        return height(root) != -1;
    }
};