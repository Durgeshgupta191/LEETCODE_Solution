class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;
         // a stores ways to reach stair 1
        int a = 1;

        // b stores ways to reach stair 2
        int b = 2;

        // Iterate from stair 3 to stair n
        for (int i = 3; i <= n; i++) {

            // Ways to reach current stair
            // = ways from previous stair
            // + ways from second previous stair
            int c = a + b;

            // Move the window forward
            a = b;
            b = c;
        }

        // b now contains ways to reach stair n
        return b;
    }
};