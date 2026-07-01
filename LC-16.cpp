class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        // Sort the array to use the two-pointer approach
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // Initialize the answer with the first possible triplet sum
        int closest = nums[0] + nums[1] + nums[2];

        // Fix the first element of the triplet
        for (int i = 0; i < n - 2; i++) {

            // Two pointers
            int left = i + 1;
            int right = n - 1;

            while (left < right) {

                // Calculate the current triplet sum
                int sum = nums[i] + nums[left] + nums[right];

                // Update closest if the current sum is nearer to the target
                if (abs(target - sum) < abs(target - closest))
                    closest = sum;

                // Need a larger sum, move left pointer
                if (sum < target) {
                    left++;
                }

                // Need a smaller sum, move right pointer
                else if (sum > target) {
                    right--;
                }

                // Exact target found
                else {
                    return target;
                }
            }
        }

        // Return the closest sum found
        return closest;
    }
};