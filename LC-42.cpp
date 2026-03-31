class Solution {
public:
    int trap(vector<int>& height) {
        // Initialize two pointers at both ends of the array
        int left = 0, right = height.size() - 1;

        // These track the maximum height seen so far from both directions
        int left_max = 0, right_max = 0;

        // Variable to store the total trapped water
        int total_water = 0;

        // Traverse the array from both ends toward the center
        while (left < right) {
            // If the height at left is smaller, process from left
            if (height[left] < height[right]) {
                // Update left_max if needed
                if (height[left] >= left_max) {
                    left_max = height[left];
                } else {
                    // Water trapped is the difference between left_max and current height
                    total_water += left_max - height[left];
                }
                left++; // Move the left pointer to the right
            }
            // If the height at right is smaller or equal, process from right
            else {
                // Update right_max if needed
                if (height[right] >= right_max) {
                    right_max = height[right];
                } else {
                    // Water trapped is the difference between right_max and current height
                    total_water += right_max - height[right];
                }
                right--; // Move the right pointer to the left
            }
        }

        // Return the total trapped water
        return total_water;
    }
};
