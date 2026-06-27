class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Hash map to store the frequency of each element
        unordered_map<int, int> freq;

        // Count the frequency of every number in the array
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        // Traverse the map to find the element
        // whose frequency is exactly 1
        for (auto j : freq) {
            if (j.second == 1) {
                return j.first; // Return the unique element
            }
        }

        // This line will never execute as per problem constraints
        return -1;
    }
};