// find preorder and show result in array 

class Solution {
public:
    vector<int> result;
    vector<int> preorderTraversal(TreeNode* root) {
        

        if(root==NULL){
            return result;
        }   
        result.push_back(root->val);

        preorderTraversal(root->left);
        preorderTraversal(root->right);

        return result;
    }
};