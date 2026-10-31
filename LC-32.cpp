
class Solution {
public:
    int longestValidParentheses(string s) {

        stack<int> st;

        // Initially -1 push karenge
        // Ye base index ka kaam karega
        st.push(-1);

        int maxi = 0;

        for (int i = 0; i < s.size(); i++) {

            // Agar opening bracket hai
            // Toh uska index stack mein push karo
            if (s[i] == '(') {
                st.push(i);
            }

            else {

                // Closing bracket aane par pop karo
                st.pop();

                // Agar stack empty ho gaya
                // Toh current index ko new base bana do
                if (st.empty()) {
                    st.push(i);
                }

                else {

                    // Valid substring ki length calculate karo
                    int len = i - st.top();

                    // Maximum length update karo
                    maxi = max(maxi, len);
                }
            }
        }

        return maxi;
    }
};
