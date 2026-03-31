// Valid Parentheses    

class Solution {
    public:
        bool isValid(string s) {
            stack<char> st; // stack to keep track of opening brackets
            
            // mapping of closing brackets to their corresponding opening brackets
            unordered_map<char, char> mapping = {
                {')', '('}, {']', '['}, {'}', '{'}
            };
            
            // iterate through each character in the string
            for (char c : s) {
                // if current char is a closing bracket
                if (mapping.find(c) != mapping.end()) { 
                    // check top element of stack (if exists), else assign dummy value '#'
                    if (st.empty() || st.top() != mapping[c]) {
                        // invalid if stack empty or doesn't match the expected opening bracket
                        return false;
                    }
                    // matched correctly → remove the top element from stack
                    st.pop();
                } 
                else { 
                    // if it's an opening bracket, push it onto stack
                    st.push(c);
                }
            }
            // valid only if stack is completely empty at the end
            return st.empty();
        }
    };
    