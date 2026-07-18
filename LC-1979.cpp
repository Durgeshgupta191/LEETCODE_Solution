// GREATEST COMMON DIVISOR

class Solution {
public:
    // Function to find GCD using Euclid's Algorithm
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;   // Store current value of b
            b = a % b;      // Update b with remainder
            a = temp;       // Move previous b to a
        }
        return a;           // a contains the GCD
    }

    int findGCD(vector<int>& nums) {

        // Initialize minimum and maximum values
        int minn = INT_MAX;
        int maxn = INT_MIN;

        // Traverse the array to find minimum and maximum elements
        for (int i = 0; i < nums.size(); i++) {
            minn = min(nums[i], minn);
            maxn = max(nums[i], maxn);
        }

        // Return GCD of the minimum and maximum elements
        return gcd(minn, maxn);
    }
};