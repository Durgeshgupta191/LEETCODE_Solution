// Simplify Path 

class Solution {
    public:
        string simplifyPath(string path) {
            vector<string> st;          // stack to store valid directory names
            string token;               // temporary string to hold parts of the path
            stringstream ss(path);      // use stringstream to split by '/'
    
            // split path into tokens separated by '/'
            while (getline(ss, token, '/')) {
                if (token == "" || token == ".") {
                    // skip empty tokens (caused by '//' or leading '/')
                    // and skip '.' (current directory, no effect)
                    continue;
                } else if (token == "..") {
                    // ".." means go one directory up, so pop from stack if not empty
                    if (!st.empty()) st.pop_back();
                } else {
                    // otherwise, it's a valid directory/file name → push to stack
                    st.push_back(token);
                }
            }
    
            // build the canonical path from the stack
            string res = "/";           // canonical path must start with "/"
            for (int i = 0; i < st.size(); i++) {
                res += st[i];           // add directory name
                if (i != st.size() - 1) res += "/"; // add "/" between names
            }
    
            return res;                 // return the simplified path
        }
    };
    