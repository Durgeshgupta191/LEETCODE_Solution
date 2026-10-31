
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        // Number of rows in the matrix
        int m = matrix.size();

        // Number of columns in the matrix
        int n = matrix[0].size();

        // Imagine the entire matrix as a sorted 1D array
        // First index = 0, last index = m*n - 1
        int low = 0;             
        int high = m * n - 1;

        // Apply Binary Search on the imaginary 1D array
        while (low <= high) {

            // Find the middle index safely
            int mid = low + (high - low) / 2;

            // *******************Convert 1D index into 2D matrix coordinates***************
            // Division gives the row number
            int row = mid / n;

            // Modulo gives the column number
            int col = mid % n;

            // Get the element present at the middle index
            int value = matrix[row][col];

            // If the middle element equals the target,
            // we have found the target
            if (value == target) {
                return true;
            }

            // If the middle element is smaller than target,
            // search in the right half
            else if (value < target) {
                low = mid + 1;
            }

            // If the middle element is greater than target,
            // search in the left half
            else {
                high = mid - 1;
            }
        }

        // If the loop ends, the target is not present
        return false;
    }
};
