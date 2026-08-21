//to check palindrome or not 

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;                   // Pointer starting from the beginning
        int right = (int)s.size() - 1; // Pointer starting from the end
        
        while (left < right) {
            // Skip characters that are not alphanumeric from the left side
            while (left < right && !isalnum(s[left])) {
                left++;
            }

            // Skip characters that are not alphanumeric from the right side
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            // Convert both characters to lowercase for case-insensitive comparison
            if (tolower(s[left]) != tolower(s[right])) {
                return false; // Not a palindrome
            }

            // Move both pointers inward
            left++;
            right--;
        }

        // If the entire string has been checked without mismatches, it's a palindrome
        return true;
    }
};
