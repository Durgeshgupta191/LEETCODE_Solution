class Solution {
public:
    int minDepth(TreeNode* root) {

        if(root == NULL){
            return 0;
        }

        // Leaf node
        if(root->left == NULL && root->right == NULL){
            return 1;
        }

        // Only right subtree exists
        if(root->left == NULL){
            return minDepth(root->right) + 1;
        }

        // Only left subtree exists
        if(root->right == NULL){
            return minDepth(root->left) + 1;
        }

        // Both subtrees exist
        return min(minDepth(root->left),
                   minDepth(root->right)) + 1;
    }
};