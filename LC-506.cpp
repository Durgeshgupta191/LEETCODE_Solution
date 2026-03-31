// RELATIVE RANKS 

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {

        int n = score.size();

        // Store score along with original index
        vector<pair<int, int>> athletes;
        for (int i = 0; i < n; i++) {
            athletes.push_back({score[i], i});
        }

        // Sort athletes by score in descending order
        sort(athletes.begin(), athletes.end(), greater<>());

        // Result array to store final ranks
        vector<string> result(n);

        // Assign ranks based on sorted order
        for (int i = 0; i < n; i++) {

            int originalIndex = athletes[i].second;

            // Assign medals to top 3 athletes
            if (i == 0) {
                result[originalIndex] = "Gold Medal";
            }
            else if (i == 1) {
                result[originalIndex] = "Silver Medal";
            }
            else if (i == 2) {
                result[originalIndex] = "Bronze Medal";
            }
            // Assign rank number (i + 1) to remaining athletes
            else {
                result[originalIndex] = to_string(i + 1);
            }
        }

        // Return result in original order
        return result;
    }
};
