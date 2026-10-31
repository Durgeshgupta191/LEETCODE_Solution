
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {

        // If the tree is empty, return 0
        if (root == NULL) {
            return 0;
        }

        int sum = 0;

        // Check if the left child exists and is a leaf node
        if (root->left != NULL &&
            root->left->left == NULL &&
            root->left->right == NULL) {

            // Add the value of the left leaf
            sum += root->left->val;
        }

        // Recursively calculate the sum in the left subtree
        sum += sumOfLeftLeaves(root->left);

        // Recursively calculate the sum in the right subtree
        sum += sumOfLeftLeaves(root->right);

        // Return the total sum of left leaves
        return sum;
    }
};
