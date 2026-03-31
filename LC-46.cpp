class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, int start) {
        // Base case: one complete permutation
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }

        // Try every possibility for current position
        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);          // Choose
            backtrack(nums, start + 1);          // Explore
            swap(nums[start], nums[i]);          // Backtrack (undo)
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return result;
    }
};
