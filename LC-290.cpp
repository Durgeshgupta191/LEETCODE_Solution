// Word Pattern


class Solution {
    public:
        bool wordPattern(string pattern, string s) {
            
            // Step 1: Split string s into words
            vector<string> words;
            istringstream iss(s);
            string word;
            while (iss >> word) {
                words.push_back(word); // add each word into vector
            }
    
            // Step 2: Check if counts match (pattern length vs word count)
            if (pattern.size() != words.size()) return false;
    
            // Step 3: Create two hashmaps
            unordered_map<char, string> mapCS; // char -> string
            unordered_map<string, char> mapSC; // string -> char
    
            // Step 4: Check bijection
            for (int i = 0; i < pattern.size(); i++) {
                char c = pattern[i];
                string w = words[i];
    
                // If char already mapped but not to same word → fail
                if (mapCS.count(c) && mapCS[c] != w) return false;
    
                // If word already mapped but not to same char → fail
                if (mapSC.count(w) && mapSC[w] != c) return false;
    
                // Otherwise create mapping
                mapCS[c] = w;
                mapSC[w] = c;
            }
    
            // Step 5: If all checks pass
            return true;
        }
    };
    