// missing number 


class Solution {
public:
    int missingNumber(vector<int>& nums) {

        // Sort the array
        sort(nums.begin(), nums.end());

        // Traverse the array
        for (int i = 0; i < nums.size(); i++) {

            // If index does not match value,
            // then 'i' is the missing number
            if (nums[i] != i) {
                return i;
            }
        }

        // If all indices match,
        // then missing number is 'n'
        return nums.size();
    }
};
