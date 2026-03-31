//73. Set Matrix Zeroes

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();        // number of rows
        int m = matrix[0].size();     // number of columns

        vector<int> row(n, 1);        // row markers
        vector<int> col(m, 1);        // column markers

        // First pass: mark rows and columns that contain zero
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    row[i] = 0;       // mark row i
                    col[j] = 0;       // mark column j
                }
            }
        }

        // Second pass: set matrix cells to zero based on markers
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(row[i] == 0 || col[j] == 0){
                    matrix[i][j] = 0; // set cell to zero
                }
            }
        }
    }
};
