//find first and last occurence of a number

class Solution {
public:
    // Find first occurrence
    int findFirst(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] >= target) {
                if (nums[mid] == target)
                    ans = mid;          // possible first index
                right = mid - 1;       // move left
            }
            else {
                left = mid + 1;
            }
        }
        return {ans};
    }

    // Find last occurrence
    int findLast(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] <= target) {
                if (nums[mid] == target)
                    ans = mid;          // possible last index
                left = mid + 1;        // move right
            }
            else {
                right = mid - 1;
            }
        }
        return {ans};
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return { findFirst(nums, target), findLast(nums, target) };
    }
};
