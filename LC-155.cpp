// 155. Min Stack


class MinStack {
    private:
        stack<int> st;      // main stack for values
        stack<int> minSt;   // helper stack to track minimums
        
    public:
        MinStack() {
            // nothing special to initialize
        }
        
        void push(int val) {
            st.push(val);
            if (minSt.empty()) {
                minSt.push(val);
            } else {
                minSt.push(min(val, minSt.top())); // store new min at this level
            }
        }
        
        void pop() {
            st.pop();
            minSt.pop(); // also pop from min stack
        }
        
        int top() {
            return st.top(); // return top element of main stack
        }
        
        int getMin() {
            return minSt.top(); // return current minimum
        }
    };
    