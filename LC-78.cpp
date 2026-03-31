// SUBSET

class Solution {
public:
    // This will store all possible subsets
    vector<vector<int>> result;

    // Temporary vector to store current subset
    vector<int> current;

    // Backtracking function
    void backtrack(vector<int>& nums, int start) {

        // Add the current subset to result
        // This includes empty subset and all intermediate subsets
        result.push_back(current);

        // Try to include each element starting from index 'start'
        for (int i = start; i < nums.size(); i++) {

            // Include nums[i] in current subset
            current.push_back(nums[i]);

            // Recurse for next elements
            backtrack(nums, i + 1);

            // Backtrack: remove last added element
            // So we can try other combinations
            current.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        // Start backtracking from index 0
        backtrack(nums, 0);

        // Return all generated subsets
        return result;
    }
};
