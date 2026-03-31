class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Find the breakpoint
        // Start from second last index
        int i = n - 2;

        // Move left while array is in decreasing order
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // Step 2: If breakpoint exists
        if (i >= 0) {
            int j = n - 1;

            // Find the element just greater than nums[i]
            while (nums[j] <= nums[i]) {
                j--;
            }

            // Swap breakpoint element with next greater element
            swap(nums[i], nums[j]);
        }

        // Step 3: Reverse the suffix (right part)
        // This makes the permutation smallest possible
        reverse(nums.begin() + i + 1, nums.end());
    }
};

