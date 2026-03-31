// REMOVE DUPLICATE FROM SI=ORTED ARRAY II

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Pointer 'i' keeps track of the position to insert the next valid element
        int i = 0;

        // Traverse all elements in the input array
        for (int num : nums) {
            // If fewer than 2 elements are added so far, always add the current number
            // OR if the current number is not the same as the number at position i-2,
            // it means it has occurred less than twice → safe to add
            if (i < 2 || nums[i - 2] != num) {
                nums[i] = num; // Insert valid number at position 'i'
                i++;           // Move to the next position
            }
        }

        // 'i' now represents the length of the final array with at most two duplicates
        return i;
    }
};
