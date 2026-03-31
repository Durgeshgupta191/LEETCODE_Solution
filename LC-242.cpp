// Valid Anagram

class Solution {
    public:
        bool isAnagram(string s, string t) {
            // If lengths don't match, they can't be anagrams
            if (s.length() != t.length()) return false;
    
            // Frequency array for 26 letters
            vector<int> count(26, 0);
    
            // Count characters in s and t
            for (int i = 0; i < s.length(); i++) {
                count[s[i] - 'a']++;  // increase for s
                count[t[i] - 'a']--;  // decrease for t
            }
    
            // If all counts are zero, they are anagrams
            for (int c : count) {
                if (c != 0) return false;
            }
            return true;
        }
    };
    