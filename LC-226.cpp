//invert binary tree

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        // If tree is empty, return NULL
        if(root == NULL){
            return NULL;
        }

        // Swap left and right child
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // Recursively invert left subtree
        invertTree(root->left);

        // Recursively invert right subtree
        invertTree(root->right);

        // Return the root after inversion
        return root;
    }
};