// Contains Duplicate II

c#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // Map to store the last index at which each number appeared
        unordered_map<int, int> seen;

        // Iterate through the array
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i]; // current number

            // Check if the number has been seen before
            if (seen.count(num) >= 1) {
                // If the difference between current index and last seen index <= k
                if (i - seen[num] <= k) {
                    return true; // Found nearby duplicate
                }
            }

            // Update the last seen index for this number
            seen[num] = i;
        }

        // If no such pair exists, return false
        return false;
    }
};
