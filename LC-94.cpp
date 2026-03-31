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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;              // To store the inorder traversal
        TreeNode* curr = root;        // Start from the root

        while (curr != NULL) {
            if (curr->left == NULL) {
                // Case 1: No left child → Visit node and go right
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                // Case 2: Has left child → Find the inorder predecessor (IP)
                TreeNode* IP = curr->left;
                
                // Move to the rightmost node in left subtree OR stop if thread already exists
                while (IP->right != NULL && IP->right != curr) {
                    IP = IP->right;
                }

                if (IP->right == NULL) {
                    // Make a temporary thread from predecessor to current node
                    IP->right = curr;
                    curr = curr->left;  // Move to left subtree
                } else {
                    // Thread exists: break it, visit node, move right
                    IP->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};
