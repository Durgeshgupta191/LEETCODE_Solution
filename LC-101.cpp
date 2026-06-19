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

    bool isHelper(TreeNode* left , TreeNode* right){
        if(right==NULL && left ==NULL){
            return true;
        }
        if(right==NULL || left==NULL){
            return false;
        }
        if(left->val==right->val){
            return isHelper(left->left,right->right) && 
                   isHelper(left->right,right->left);
        }
        return false;
    }

    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        return isHelper(root->left,root->right);
    }
    
};