/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int prevOrder = 0; // Counter to keep track of the number of visited nodes in in-order traversal

    int kthSmallest(TreeNode* root, int k) {
        // Base case: if the node is NULL, return -1
        if (root == NULL) {
            return -1;
        }

        // Traverse the left subtree
        if (root->left != NULL) {
            int leftAns = kthSmallest(root->left, k);
            if (leftAns != -1) {
                return leftAns; // If kth smallest found in left subtree, return it
            }
        }

        // Visit the current node
        prevOrder = prevOrder + 1;
        if (prevOrder == k) {
            return root->val; // If current node is the kth visited node, return its value
        }

        // Traverse the right subtree
        if (root->right != NULL) {
            int rightAns = kthSmallest(root->right, k);
            if (rightAns != -1) {
                return rightAns; // If kth smallest found in right subtree, return it
            }
        }

        // If kth element is not found, return -1
        return -1;
    }
};
