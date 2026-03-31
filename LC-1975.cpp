class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {

        long long sumAbs = 0;   // Will store sum of absolute values
        int negCount = 0;       // Count of negative numbers
        int minAbs = INT_MAX;   // Smallest absolute value

        // Traverse the matrix using index-based loops
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {

                int val = matrix[i][j];  // Current element

                // Count negative numbers
                if (val < 0)
                    negCount++;

                // Add absolute value to sum
                sumAbs = sumAbs + abs(val);

                // Keep track of smallest absolute value
                minAbs = min(minAbs, abs(val));
            }
        }

        // If number of negatives is even, all can be made positive
        if (negCount % 2 == 0)
            return sumAbs;

        // If odd, one smallest value must remain negative
        return sumAbs - 2LL * minAbs;
    }
};
