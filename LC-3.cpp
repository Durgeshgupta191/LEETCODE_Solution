// Longest Substring Without Repeating Characters


class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();

        // Two pointers for the sliding window
        int left = 0, right = 0;

        // Stores the maximum length of a substring without repeating characters
        int maxLen = 0;

        // Stores unique characters present in the current window
        unordered_set<char> window;

        // Expand the window until the end of the string
        while (right < n) {

            // If current character is not already in the window
            if (window.find(s[right]) == window.end()) {

                // Add the character to the window
                window.insert(s[right]);

                // Update the maximum window size
                maxLen = max(maxLen, right - left + 1);

                // Expand the window
                right++;
            }
            else {
                // Duplicate found:
                // Remove the leftmost character and shrink the window
                window.erase(s[left]);
                left++;
            }
        }

        // Return the maximum length found
        return maxLen;
    }
};