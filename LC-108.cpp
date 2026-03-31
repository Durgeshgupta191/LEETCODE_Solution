class Solution {
public:
    // Helper function to recursively build the BST
    TreeNode* node(vector<int>& nums, int st, int end) {
        // Base case: if start index is greater than end, return NULL (no node to create)
        if (st > end) {
            return NULL;
        }
        
        int mid = st + (end - st) / 2;  // Find the middle element to maintain balance

        // Create a new TreeNode with the middle element
        TreeNode* root = new TreeNode(nums[mid]);

        // Recursively build the left subtree using the left half of the array
        root->left = node(nums, st, mid - 1);

        // Recursively build the right subtree using the right half of the array
        root->right = node(nums, mid + 1, end);

        // Return the current root node
        return root;
    }

    // Main function to convert sorted array to a height-balanced BST
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // Call the helper function with the full array range
        return node(nums, 0, nums.size() - 1);
    }
};

