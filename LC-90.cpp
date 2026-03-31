
// SUBSET II


class Solution {
public:
    // Stores all unique subsets
    vector<vector<int>> result;

    // Stores the current subset during recursion
    vector<int> current;

    // Backtracking function to generate subsets
    void backtrack(vector<int>& nums, int start) {

        // Add the current subset to the result
        // This includes empty subset and all valid combinations
        result.push_back(current);

        // Loop through remaining elements starting from 'start'
        for (int i = start; i < nums.size(); i++) {

            // Skip duplicate elements at the same recursion level
            // i > start ensures we only skip duplicates in the same level
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }

            // Choose the current element
            current.push_back(nums[i]);

            // Recurse to generate subsets using next elements
            backtrack(nums, i + 1);

            // Backtrack: remove last chosen element
            // So other combinations can be explored
            current.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        // Sort the array so duplicate elements come together
        sort(nums.begin(), nums.end());

        // Start backtracking from index 0
        backtrack(nums, 0);

        // Return all unique subsets
        return result;
    }
};
