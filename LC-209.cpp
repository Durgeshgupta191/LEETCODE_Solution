//  Leetcode 209. Minimum Size Subarray Sum

class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int n = nums.size();
            int left = 0;                  // Left pointer of the sliding window
            int sum = 0;                   // Current sum of the sliding window
            int minLen = INT_MAX;          // Track the minimal subarray length (start with "infinity")
    
            // Expand the window with right pointer
            for (int right = 0; right < n; right++) {
                sum += nums[right];        // Add current element to the window sum
    
                // While current window sum >= target, try to shrink from the left
                while (sum >= target) {
                    // Update minimal length if current window is smaller
                    minLen = min(minLen, right - left + 1);
    
                    // Shrink the window from left side
                    sum -= nums[left];
                    left++;
                }
            }
    
            // If no valid subarray found, return 0. Otherwise return the minimum length found
            return (minLen == INT_MAX) ? 0 : minLen;
        }
    };
    