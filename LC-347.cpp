//TOP -K FREQUENT ELEMENT

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // Step 1: Count frequency of each element
        unordered_map<int, int> freq;
        for(int num : nums) {
            freq[num]++;
        }

        // Step 2: Store frequency and number in a vector
        vector<pair<int, int>> v;
        for(auto it : freq) {
            v.push_back({it.second, it.first}); 
            // {frequency, number}
        }

        // Step 3: Sort vector in descending order of frequency
        sort(v.begin(), v.end(), greater<pair<int, int>>());

        // Step 4: Store first k elements
        vector<int> result;
        for(int i = 0; i < k; i++) {
            result.push_back(v[i].second);
        }

        return result;
    }
};
