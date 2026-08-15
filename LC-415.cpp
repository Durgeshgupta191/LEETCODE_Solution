class Solution {
public:
    string addStrings(string num1, string num2) {

        // Start from the last digit of both strings
        int i = num1.size() - 1;
        int j = num2.size() - 1;

        // Carry generated during addition
        int carry = 0;

        // Store the answer
        string ans = "";

        // Continue while digits or carry are remaining
        while (i >= 0 || j >= 0 || carry) {

            // Initially assume both digits are 0
            int digit1 = 0;
            int digit2 = 0;

            // Get digit from num1 if available
            if (i >= 0) {
                digit1 = num1[i] - '0';
                i--;
            }

            // Get digit from num2 if available
            if (j >= 0) {
                digit2 = num2[j] - '0';
                j--;
            }

            // Add both digits along with carry
            int sum = digit1 + digit2 + carry;

            // Get the current digit
            // Example: 17 % 10 = 7
            ans += char((sum % 10) + '0');

            // Calculate carry
            // Example: 17 / 10 = 1
            carry = sum / 10;
        }

        // Digits were added from right to left,
        // so reverse the answer
        reverse(ans.begin(), ans.end());

        return ans;
    }
};