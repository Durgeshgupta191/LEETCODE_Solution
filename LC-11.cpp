class Solution {
public:
    int maxArea(vector<int>& height) {

        // Left pointer starts at first element
        int i = 0;

        // Right pointer MUST start at the last index
        int j = height.size() - 1;

        // Maximum water found so far
        int maxWater = 0;

        // Continue until both pointers meet
        while (i < j) {

            // The smaller height determines
            // how much water the container can hold
            int length = min(height[i], height[j]);

            // Distance between the two pointers
            int base = j - i;

            // Current amount of water
            int currWater = length * base;

            // Keep the maximum value
            maxWater = max(currWater, maxWater);

            // Move the pointer with smaller height
            if (height[i] < height[j]) {
                i++;
            }
            else {
                j--;
            }
        }

        return maxWater;
    }
};