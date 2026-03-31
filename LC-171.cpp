//171. Excel Sheet Column Number

class Solution {
public:
    int titleToNumber(string columnTitle) {

        int result = 0;  // stores final column number

        // Traverse each character in the string
        for (char ch : columnTitle) {

            // Convert character to number
            // 'A' -> 1, 'B' -> 2, ..., 'Z' -> 26
            int value = ch - 'A' + 1;

            // Multiply previous result by 26
            // and add current value
            result = result * 26 + value;
        }

        return result;
    }
};
