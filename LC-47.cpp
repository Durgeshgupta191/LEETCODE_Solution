
//47. Permutations II

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;          // To store all unique permutations
        
        sort(nums.begin(), nums.end());      // Step 1: Sort to start with smallest permutation
        
        do {
            result.push_back(nums);          // Step 2: Store the current permutation
        } while (next_permutation(nums.begin(), nums.end()));  
        // Step 3: Generate next lexicographical permutation until none left
        
        return result;                       // Return all collected permutations
    }
};
