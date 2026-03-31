// RANSOME NOTE

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> freq; // store character counts

        // Step 1: Count each character in magazine
        for (char c : magazine) {
            freq[c]++;
        }

        // Step 2: For each char in ransomNote, try to use one
        for (char c : ransomNote) {
            if (freq[c] == 0) {
                // not available or already used up
                return false;
            }
            freq[c]--; // use one occurrence
        }

        // Step 3: All characters matched
        return true;
    }
};

int main() {
    Solution sol;

    cout << boolalpha; // print true/false instead of 1/0

    // Example testcases
    cout << sol.canConstruct("a", "b") << endl;      // false
    cout << sol.canConstruct("aa", "ab") << endl;    // false
    cout << sol.canConstruct("aa", "aab") << endl;   // true

    return 0;
}
