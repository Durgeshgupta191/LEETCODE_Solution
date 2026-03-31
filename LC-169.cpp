// Mejority element 

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq = 0;  // Counter to track the frequency of the current candidate
        int ans = 0;   // Variable to store the current candidate for majority element

        // Traverse through the array
        for(int i = 0; i < nums.size(); i++) {

            // If frequency becomes 0, choose the current number as the new candidate
            if(freq == 0) {
                ans = nums[i];
            }

            // If current number matches the candidate, increase the count
            if(ans == nums[i]) {
                freq++;
            } 
            // If current number doesn't match, decrease the count
            else {
                freq--;
            }
        }

        // The final candidate is the majority element (guaranteed to exist)
        return ans;
    }
};
