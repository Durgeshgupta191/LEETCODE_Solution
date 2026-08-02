class Solution {
public:
    string convertToTitle(int columnNumber) {
        // Characters are generated from right to left.
        string ans = "";
        // Continue until the number becomes 0
        while (columnNumber > 0) {

            /*  Subtract 1 to convert them into 0-indexing:
                A = 0, B = 1, ..., Z = 25 */
            columnNumber--;

            char ch = 'A' + (columnNumber % 26);

            // Add the current character to the answer.
            // We get characters from right to left.
            ans += ch;

            /*
                Remove the last processed "digit"
                and continue with the remaining number.
            */
            columnNumber /= 26;
        }

        // Reverse once because characters were collected
        // from least significant to most significant.
        reverse(ans.begin(), ans.end());

        return ans;
    }
};