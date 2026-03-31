//  N-QUEENS

class Solution {
public:
    // Stores all valid board configurations (final answers)
    vector<vector<string>> result;

    // Represents the current chessboard
    vector<string> board;
    
    // Function to check if placing a queen at (row, col) is safe
    bool isSafe(int row, int col, int n) {

        // 1️⃣ Check same column above the current row
            // Because queens are placed row by row from top to bottom
            for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q')
                return false;  // Another queen found in same column
        }
        
        // 2️⃣ Check upper-left diagonal (↖ direction)
        // Move diagonally up-left and see if any queen exists
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;  // Queen found on upper-left diagonal
        }
        
        // 3️⃣ Check upper-right diagonal (↗ direction)
        // Move diagonally up-right and see if any queen exists
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;  // Queen found on upper-right diagonal
        }
        
        // If no conflict found, position is safe
        return true;
    }
    
    // Backtracking function to place queens row by row
    void solve(int row, int n) {

        // Base case: all rows are filled with queens
        if (row == n) {
            result.push_back(board); // Store current valid board
            return;
        }
        
        // Try placing a queen in every column of the current row
        for (int col = 0; col < n; col++) {

            // Check if it's safe to place queen at (row, col)
            if (isSafe(row, col, n)) {

                // Place the queen
                board[row][col] = 'Q';

                // Recur for the next row
                solve(row + 1, n);

                // Backtrack: remove the queen and try next column
                board[row][col] = '.';
            }
        }
    }
    
    // Main function called by LeetCode
    vector<vector<string>> solveNQueens(int n) {

        // Initialize the board with empty cells '.'
        board = vector<string>(n, string(n, '.'));

        // Start solving from the first row
        solve(0, n);

        // Return all valid solutions
        return result;
    }
};
