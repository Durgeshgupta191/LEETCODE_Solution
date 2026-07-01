class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // Stores all unique triplets
        vector<vector<int>> ans;

        int n = nums.size();

        // Sort the array for two-pointer approach
        sort(nums.begin(), nums.end());

        // Fix the first element of the triplet
        for (int i = 0; i < n; i++) {

            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // Two pointers
            int left = i + 1;
            int right = n - 1;

            while (left < right) {

                // Calculate current sum
                int sum = nums[i] + nums[left] + nums[right];

                // Triplet found
                if (sum == 0) {

                    ans.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicate values of left pointer
                    while (left < right && nums[left] == nums[left + 1])
                        left++;

                    // Skip duplicate values of right pointer
                    while (left < right && nums[right] == nums[right - 1])
                        right--;

                    // Move both pointers
                    left++;
                    right--;
                }

                // Sum is too small, move left to increase it
                else if (sum < 0) {
                    left++;
                }

                // Sum is too large, move right to decrease it
                else {
                    right--;
                }
            }
        }

        return ans;
    }
};