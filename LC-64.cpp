class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();        // number of rows
        int n = grid[0].size();     // number of columns
        
        // Step 1: Fill the first row
        // Only one way to reach each cell: from the left
        for (int j = 1; j < n; j++) {
            grid[0][j] = grid[0][j] + grid[0][j - 1];
        }
        
        // Step 2: Fill the first column
        // Only one way to reach each cell: from the top
        for (int i = 1; i < m; i++) {
            grid[i][0] = grid[i][0] + grid[i - 1][0];
        }
        
        // Step 3: Fill the rest of the grid
        // Choose minimum path from top or left
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] = grid[i][j] + 
                             min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        
        // Step 4: Bottom-right cell contains minimum path sum
        return grid[m - 1][n - 1];
    }
};
