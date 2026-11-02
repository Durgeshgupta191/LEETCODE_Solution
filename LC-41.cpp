
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        // Step 1: Sort the array in ascending order
        sort(nums.begin(), nums.end());

        // We are searching for the first missing positive number
        // Starting from 1
        int num = 1;

        // Step 2: Traverse the sorted array
        for (int i = 0; i < nums.size(); i++) {

            // If current element matches the expected number
            if (nums[i] == num) {

                // Move to the next positive number
                num++;
            }
        }

        // The number that we are expecting but didn't find
        // is our first missing positive number
        return num;
    }
};
