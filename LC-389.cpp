class Solution {
public:
    char findTheDifference(string s, string t) {

        // Frequency array for 26 lowercase letters
        vector<int> freq(26, 0);

        // Count characters in string s
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        // Remove characters using string t
        for (char ch : t) {

            // If frequency becomes negative,
            // this is the extra character
            freq[ch - 'a']--;

            if (freq[ch - 'a'] < 0) {
                return ch;
            }
        }

        return ' ';   // Never reached
    }
};