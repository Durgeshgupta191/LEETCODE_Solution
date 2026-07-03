// SUMMARY RANGE 

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();

        // Traverse the array
        for (int i = 0; i < n; i++) {

            // Mark the beginning of the current range
            int start = nums[i];

            // Keep extending the range while consecutive numbers exist
            while (i + 1 < n && nums[i + 1] == nums[i] + 1) {
                i++;
            }

            // Current range ends at nums[i]
            int end = nums[i];

            // If start and end are the same, it's a single number
            if (start == end) {
                ans.push_back(to_string(start));
            }
            // Otherwise, store the range in "start->end" format
            else {
                ans.push_back(to_string(start) + "->" + to_string(end));
            }
        }

        // Return all summary ranges
        return ans;
    }
};