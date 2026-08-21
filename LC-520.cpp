class Solution {
public:
    bool detectCapitalUse(string word) {

        int upper = 0;
        int lower = 0;

        // Count uppercase and lowercase characters
        for (char ch : word) {
            if (isupper(ch)) {
                upper++;
            } else {
                lower++;
            }
        }

        // Case 1: All uppercase
        if (upper == word.size()) {
            return true;
        }

        // Case 2: All lowercase
        if (lower == word.size()) {
            return true;
        }

        // Case 3: Only first character is uppercase
        if (isupper(word[0]) && lower == word.size() - 1) {
            return true;
        }

        return false;
    }
};