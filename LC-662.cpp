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
    int widthOfBinaryTree(TreeNode* root) {
        // Use a queue for level-order traversal. 
        // Each element in the queue is a pair of (node, index),
        // where index is the "virtual" position of the node in a complete binary tree.
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});  // Start with the root at index 0
        int maxWidth = 0;

        while (!q.empty()) {
            int currLevelSize = q.size();
            // Index of the first and last node at the current level
            unsigned long long stIdx = q.front().second;
            unsigned long long endIdx = q.back().second;

            // Calculate the width of this level
            maxWidth = max(maxWidth, (int)(endIdx - stIdx + 1));

            for (int i = 0; i < currLevelSize; i++) {
                auto curr = q.front();
                q.pop();

                // Normalize index to prevent overflow by subtracting stIdx
                unsigned long long idx = curr.second - stIdx;

                // Add left child with index 2 * idx + 1
                if (curr.first->left) {
                    q.push({curr.first->left, idx * 2 + 1});
                }
                // Add right child with index 2 * idx + 2
                if (curr.first->right) {
                    q.push({curr.first->right, idx * 2 + 2});
                }
            }
        }
        return maxWidth;  // Return the maximum width found
    }
};
