// WORD BREAK

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        // Convert wordDict into a set for O(1) lookup
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        int n = s.size();

        // dp[i] = true if s[0..i-1] can be segmented
        vector<bool> dp(n + 1, false);

        // Empty string can always be segmented
        dp[0] = true;

        // Check all prefixes of s
        for (int i = 1; i <= n; i++) {       // i = end index
            for (int j = 0; j < i; j++) {    // j = split point
                // If s[0..j-1] can be segmented AND s[j..i-1] is in dictionary
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;           // assign true, not compare
                    break;                  // no need to check further splits
                }
            }
        }

        return dp[n]; // Can the entire string be segmented?
    }
};
