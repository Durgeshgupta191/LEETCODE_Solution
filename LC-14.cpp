// FIND LONGEST COMMON PREFIX 

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        // If input array is empty, no common prefix exists
        if (strs.empty()) return "";

        // Loop through each character of the first string
        for (int i = 0; i < strs[0].length(); i++) {

            // Take current character from first string
            char ch = strs[0][i];

            // Compare this character with the same position
            // in all other strings
            for (int j = 1; j < strs.size(); j++) {

                // If index exceeds current string length
                // OR characters do not match
                if (i >= strs[j].length() || strs[j][i] != ch)
                    // Return prefix till previous character
                    return strs[0].substr(0, i);
            }
        }

        // If all characters match, return the first string
        return strs[0];
    }
};
