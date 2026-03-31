class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
    
            // i is the index where the next valid element will be placed
            int i = 0;
    
            // Traverse each element in nums
            for (int num : nums) {
    
                // If current element is NOT equal to val, keep it
                if (num != val) {
    
                    // Place the valid element at index i
                    nums[i] = num;
    
                    // Move i to the next position
                    i++;
                }
            }
    
            // i represents the new length of the array after removal
            return i;
        }
    };
    