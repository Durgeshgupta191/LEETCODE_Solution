// Valid Sudoko 

class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
            vector<unordered_set<char>> rows(9), cols(9), boxes(9);
    
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    char c = board[i][j];
                    if (c == '.') continue;
    
                    // Box index
                    int boxIndex = (i / 3) * 3 + (j / 3);
    
                    // Check row, column, and box
                    //count(c) checks if character c (the digit '1'..'9') already exists in that set.

                    if (rows[i].count(c) || cols[j].count(c) || boxes[boxIndex].count(c)) {
                        return false;
                    }
                    
                    //If no duplicates are found, we must record that this digit has now been seen in the current row, column, and box.
                    // Insert into row, column, and box sets
                    rows[i].insert(c);
                    cols[j].insert(c);
                    boxes[boxIndex].insert(c);
                }
            }
            return true;
        }
    };
    