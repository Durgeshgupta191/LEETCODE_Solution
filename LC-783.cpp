class Solution {
public:
    TreeNode* prev = NULL;  // Keeps track of the previous node in the in-order traversal

    int minDiffInBST(TreeNode* root) {
        if (root == NULL) {
            return INT_MAX;  // Base case: return large number if node is NULL
        }

        int ans = INT_MAX;

        // Traverse the left subtree (in-order traversal)
        if (root->left != NULL) {
            int leftMin = minDiffInBST(root->left);
            ans = min(ans, leftMin);  // Update answer with left subtree's min difference
        }

        // If previous node exists, calculate the difference with current node
        if (prev != NULL) {
            ans = min(ans, root->val - prev->val);  // Minimum of current answer and new difference
        }

        prev = root;  // Update prev to current node before going to the right subtree

        // Traverse the right subtree (in-order traversal)
        if (root->right != NULL) {
            int rightMin = minDiffInBST(root->right);
            ans = min(ans, rightMin);  // Update answer with right subtree's min difference
        }

        return ans;  // Return the minimum difference found
    }
};
