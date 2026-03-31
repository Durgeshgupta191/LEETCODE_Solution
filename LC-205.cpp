// 205. Isomorphic Strings  using Hashmap
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // If lengths differ, they can never be isomorphic
        if (s.length() != t.length()) return false;

        // Two hashmaps:
        // mapST: maps characters from s -> t
        // mapTS: maps characters from t -> s
        // (We use both to ensure one-to-one mapping in both directions)
        unordered_map<char, char> mapST; 
        unordered_map<char, char> mapTS; 

        // Traverse both strings together
        for (int i = 0; i < s.length(); i++) {
            char c1 = s[i]; // character from s
            char c2 = t[i]; // corresponding character from t

            // Case 1: If c1 is already mapped, 
            // check if it maps to the same c2 as before.
            // If not, the mapping is inconsistent → not isomorphic.
            if (mapST.count(c1) && mapST[c1] != c2) 
                return false;

            // Case 2: If c2 is already mapped, 
            // check if it maps back to the same c1 as before.
            // If not, then two different characters from s 
            // are trying to map to the same c2 → not isomorphic.
            if (mapTS.count(c2) && mapTS[c2] != c1) 
                return false;

            // Otherwise, create/update mapping in both directions
            mapST[c1] = c2; 
            mapTS[c2] = c1;
        }

        // If all characters mapped consistently, return true
        return true;
    }
};

int main() {
    Solution sol;
    cout << boolalpha;

    cout << sol.isIsomorphic("egg", "add") << endl;     /
    cout << sol.isIsomorphic("foo", "bar") << endl;     
    cout << sol.isIsomorphic("paper", "title") << endl; 

    return 0;
}
