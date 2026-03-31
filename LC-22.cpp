//Generate Parentheses


class Solution {
public:

    // Stores all valid combinations of parentheses
    vector<string> result;

    // curr  -> current parentheses string being formed
    // open  -> number of '(' used so far
    // close -> number of ')' used so far
    // n     -> total number of pairs required
    void backTrack(string curr, int open, int close, int n) {

        // Base case:
        // If the length of current string becomes 2*n,
        // it means we have used n '(' and n ')'
        if (curr.length() == 2 * n) {
            result.push_back(curr);   // store the valid combination
            return;
        }

        // Add '(' if we still have opening brackets left
        if (open < n) {
            backTrack(curr + "(", open + 1, close, n);
        }

        // Add ')' only if it will not make the string invalid
        // i.e., closing brackets should be less than opening ones
        if (close < open) {
            backTrack(curr + ")", open, close + 1, n);
        }
    }

    // Main function called by LeetCode
    vector<string> generateParenthesis(int n) {

        // Start backtracking with empty string
        // open = 0, close = 0
        backTrack("", 0, 0, n);

        // Return all valid parentheses combinations
        return result;
    }
};
