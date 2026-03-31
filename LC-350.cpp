// Intersection of Two Arrays II

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, int> freq;   // Step 1: Create a map to store counts
        vector<int> result;             // Step 2: This will store the answer

        // Step 3: Count how many times each number appears in nums1
        for (int num : nums1) {
            freq[num]++;                // Example: if num = 2, freq[2] becomes 1, then 2, etc.
        }

        // Step 4: Check each number in nums2
        for (int num : nums2) {
            if (freq[num] > 0) {        // If this number exists in nums1
                result.push_back(num);  // Add it to result
                freq[num]--;           // Reduce count so duplicates are handled correctly
            }
        }

        // Step 5: Return the final intersection
        return result;
    }
};
