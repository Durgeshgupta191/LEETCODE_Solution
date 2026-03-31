// Product of Array except itself

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1); // Initialize result with 1s

        // Step 1: Prefix product
        int prefix = 1;
        for (int i = 0; i < n; ++i) {
            result[i] = prefix;     // Product of all elements to the left of i
            prefix *= nums[i];      // Update prefix for next index
        }

        // Step 2: Suffix product and final result
        int suffix = 1;
        for (int i = n - 1; i >= 0; --i) {
            result[i] *= suffix;    // Multiply by product of elements to the right
            suffix *= nums[i];      // Update suffix for next index
        }

        return result;
    }
};

/*   dry run
                nums = [1,2,3,4]

    prifix = [1,1,2,6]          suffix = [24,12,4,1]

            result = prifix*Suffix = [24,12,8,6]

*/