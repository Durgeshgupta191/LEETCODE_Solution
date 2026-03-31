//number to roman number
 
class Solution {
public:
    string intToRoman(int num) {
        // Define all Roman numeral values and their corresponding symbols in descending order
        vector<int> values = {
            1000, 900, 500, 400,
            100, 90, 50, 40,
            10, 9, 5, 4, 1
        };

        vector<string> symbols = {
            "M", "CM", "D", "CD",
            "C", "XC", "L", "XL",
            "X", "IX", "V", "IV", "I"
        };

        string result = "";  // This will hold the final Roman numeral

        // Loop through each value-symbol pair
        for (int i = 0; i < values.size(); ++i) {
            // While the current value can be subtracted from num
            while (num >= values[i]) {
                num -= values[i];              // Subtract the value from num
                result += symbols[i];          // Append the corresponding Roman symbol
            }
        }

        return result;  // Return the constructed Roman numeral
    }
};