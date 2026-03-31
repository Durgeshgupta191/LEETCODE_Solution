class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        // This vector will store the spiral order result
        vector<int> result;

        // Number of columns
        int n = matrix[0].size();

        // Number of rows
        int m = matrix.size();

        // Initialize boundaries
        int top = 0;          // starting row
        int bottom = m - 1;   // ending row
        int left = 0;         // starting column
        int right = n - 1;    // ending column

        // Loop until all elements are covered
        while (left <= right && top <= bottom) {

            // 1️⃣ Traverse from LEFT to RIGHT (top row)
            for (int j = left; j <= right; j++) {
                result.push_back(matrix[top][j]);
            }
            // Move top boundary down
            top++;

            // 2️⃣ Traverse from TOP to BOTTOM (right column)
            for (int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            // Move right boundary left
            right--;

            // 3️⃣ Traverse from RIGHT to LEFT (bottom row)
            // Check is needed to avoid duplicate traversal
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    result.push_back(matrix[bottom][j]);
                }
                // Move bottom boundary up
                bottom--;
            }

            // 4️⃣ Traverse from BOTTOM to TOP (left column)
            // Check is needed to avoid duplicate traversal
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                // Move left boundary right
                left++;
            }
        }

        // Return spiral order
        return result;
    }
};
