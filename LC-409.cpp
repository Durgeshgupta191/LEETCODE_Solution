class Solution {
public:
    int longestPalindrome(string s) {

        // Store frequency of each character
        unordered_map<char, int> freq;

        // Count every character
        for (char ch : s) {
            freq[ch]++;
        }

        int ans = 0;
        bool oddNum = false;

        // Check frequency of every character
        for (auto fq : freq) {

            // Add only the even part of the frequency
            // Example: 5 -> 4, 4 -> 4
            ans += (fq.second / 2) * 2;

            // Check if frequency is odd
            if (fq.second % 2 == 1) {
                oddNum = true;
            }
        }

        // If any odd frequency exists,
        // use one character in the center
        if (oddNum) {
            ans++;
        }

        return ans;
    }
};
