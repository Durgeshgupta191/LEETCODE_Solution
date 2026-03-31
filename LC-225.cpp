class MyStack {
public:
    // Two queues are used to simulate stack behavior
    queue<int> q1;  // Main queue (always keeps the stack elements in correct order)
    queue<int> q2;  // Temporary helper queue

    // Constructor
    MyStack() {
        // No initialization needed
    }
    
    // Push element x onto stack
    void push(int x) {
        // Step 1: Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Step 2: Push the new element into q1 (so it becomes the front)
        q1.push(x);

        // Step 3: Move everything back from q2 to q1
        // This ensures the most recently pushed element is always at the front of q1
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    // Removes the element on top of the stack and returns it
    int pop() {
        int ans = q1.front();  // The front of q1 is the "top" of the simulated stack
        q1.pop();              // Remove the top element
        return ans;            // Return it
    }
    
    // Get the top element
    int top() {
        return q1.front();  // The front of q1 always holds the current top
    }
    
    // Return whether the stack is empty
    bool empty() {
        return q1.empty();  // If q1 is empty, the stack is empty
    }
};
