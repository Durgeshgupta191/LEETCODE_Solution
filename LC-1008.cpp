#include <vector>
#include <climits>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Helper function to construct BST from preorder traversal
    TreeNode* helper(vector<int>& preorder, int &i, int range) {
        // Base case: If all elements are processed or current element exceeds the allowed range
        if (i >= preorder.size() || preorder[i] > range) {
            return nullptr;
        }

        // Create root node with current value
        TreeNode* root = new TreeNode(preorder[i]);
        i++;

        // Recursivly for left subtree with updated upper range
        root->left = helper(preorder, i, root->val);

        // Recursivly for right subtree with current upper range
        root->right = helper(preorder, i, range);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return helper(preorder, i, INT_MAX);
    }
};
