class Solution {
public:
    int countSegments(string s) {

        int word = 0;

        for (int i = 0; i < s.size(); i++) {

            // Current character is not a space
            // AND it is the first character
            // OR previous character was a space
            if (s[i] != ' ' && (i == 0 || s[i - 1] == ' ')) {
                word++;
            }
        }

        return word;
    }
};