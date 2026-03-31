class MyQueue {
public:
    // Two stacks to simulate queue behavior
    stack<int> s1; // Main stack where the front of the queue is on the top
    stack<int> s2; // Temporary stack used during push

    // Constructor
    MyQueue() {
        // No initialization needed
    }
    
    // Push element x to the back of the queue
    void push(int x) {
        // Step 1: Move all elements from s1 to s2 (reverse the order)
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Step 2: Push the new element to s1 (it's at the bottom of the queue logically)
        s1.push(x);

        // Step 3: Move everything back from s2 to s1 (restores original order with x at the bottom)
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    // Removes the element from the front of the queue and returns it
    int pop() {
        int ans = s1.top();  // Top of s1 is the front of the queue
        s1.pop();            // Remove the front element
        return ans;          // Return it
    }
    
    // Get the front element of the queue
    int peek() {
        return s1.top();     // Top of s1 is the front of the queue
    }
    
    // Return whether the queue is empty
    bool empty() {
        return s1.empty();   // If s1 is empty, the queue is empty
    }
};
