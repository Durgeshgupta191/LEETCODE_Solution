class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Edge case: if the array is empty, return 0
        if (nums.empty()) return 0;

        // i keeps track of the position to place the next unique element
        int i = 0;

        // Loop through the array starting from the second element
        for (int j = 1; j < nums.size(); j++) {
            // If the current element is not equal to the last unique one
            if (nums[j] != nums[i]) {
                i++;               // Move to the next position
                nums[i] = nums[j]; // Place the unique element at position i
            }
            // If nums[j] == nums[i], it's a duplicate, so we skip it
        }

        // The number of unique elements is i + 1
        return i + 1;
    }
};
