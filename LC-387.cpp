class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;  // Map to count occurrences of each character
        queue<int> q;                // Queue to store indices of characters that could be unique

        for (int i = 0; i < s.size(); i++) {
            // If this character is seen for the first time, store its index
            if (m.find(s[i]) == m.end()) {
                q.push(i);  // Add the index to the queue
            }

            m[s[i]]++;  // Increment character count in the map

            // While the front of the queue is a character that has appeared more than once
            while (!q.empty() && m[s[q.front()]] > 1) {
                q.pop();  // Remove it from the queue as it's not unique anymore
            }
        }

        // If the queue is empty, no unique character was found
        // Otherwise, return the index of the first unique character
        return q.empty() ? -1 : q.front();
    }
};
