// Lowest common ancestor in Binary Search tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;            // Value of the node
 *     TreeNode *left;     // Pointer to the left child
 *     TreeNode *right;    // Pointer to the right child
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {} // Constructor
 * };
 */

class Solution {
public:
    /**
     * Finds the lowest common ancestor (LCA) of two nodes in a BST.
     * @param root The root of the BST.
     * @param p Pointer to the first node.
     * @param q Pointer to the second node.
     * @return Pointer to the LCA node.
     */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if the current node is null, return null
        if (root == NULL) {
            return NULL;
        }

        // If both p and q are less than root, LCA lies in the left subtree
        if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }

        // If both p and q are greater than root, LCA lies in the right subtree
        else if (root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }

        // If p and q lie on different sides of root, root is their LCA
        else {
            return root;
        }
    }
};
