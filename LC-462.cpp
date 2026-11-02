
class Solution {
public:
    int minMoves2(vector<int>& nums) {

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Find the median
        int median = nums[nums.size() / 2];

        int count = 0;

        // Step 3: Calculate total moves
        for(int i = 0; i < nums.size(); i++) {

            // Absolute difference gives minimum moves
            count += abs(nums[i] - median);
        }

        // Step 4: Return total moves
        return count;
    }
};
