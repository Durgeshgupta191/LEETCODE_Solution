//LC-100. Same Tree

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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // Case 1: If both nodes are NULL, trees are identical at this point
        if(p == NULL && q == NULL){
            return true;
        }

        // Case 2: If one node is NULL and the other is not,
        // trees are not identical
        if(p == NULL || q == NULL){
            return false;
        }

        // Case 3: If values of the current nodes are different,
        // trees are not the same
        if(p->val != q->val){
            return false;
        }

        // Recursively check the right subtree of both trees
        bool right = isSameTree(p->right, q->right);

        // Recursively check the left subtree of both trees
        bool left = isSameTree(p->left, q->left);

        // Trees are the same only if both left and right subtrees are same
        return left && right;
    }
};