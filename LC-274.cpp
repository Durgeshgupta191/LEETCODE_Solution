//  find H-index (number of citation[i]>= i+1)

class Solution {
public:
    int hIndex(vector<int>& citations) {
        // Step 1: Sort the array in descending order
        sort(citations.rbegin(), citations.rend());

        int h = 0;

        // Step 2: Iterate through the sorted array
        for (int i = 0; i < citations.size(); i++) {
            // Check if the current paper has at least (i + 1) citations
            if (citations[i] >= i + 1) {
                // If yes, update h-index
                h = i + 1;
            } else {
                // If not, we can't go further; break out
                break;
            }
        }

        // Step 3: Return the final h-index value
        return h;
    }
};
