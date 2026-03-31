class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {

        // If tree is empty
        if(root == NULL){
            return false;
        }

        // If leaf node
        if(root->left == NULL && root->right == NULL){
            return root->val == targetSum;
        }

        // Remaining sum
        int re_sum = targetSum - root->val;

        // Check left OR right subtree
        return hasPathSum(root->left, re_sum) ||
               hasPathSum(root->right, re_sum);
    }
};