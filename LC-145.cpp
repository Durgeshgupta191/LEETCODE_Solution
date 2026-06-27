// Find PostOrder Travarsal of the tree



class Solution{
    public:
    vector<int> res;
        vector<int> postorderTraversal(TreeNode* root){

            if(root == NULL){
                return res;
            }
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            res.push_back(root->val);

            return res;
    }
};