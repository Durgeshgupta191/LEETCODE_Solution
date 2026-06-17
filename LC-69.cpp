class Solution {
public:
    int mySqrt(int x) {
        // Base case:
        if (x < 2) {
            return x;
        }
        // Search space for the square root lies between 1 and x
        int left = 1;
        int right = x;
        int ans = 0; // ans Needed when x is not a perfect square

        // Perform Binary Search
        while (left <= right) {
            int mid = left + (right - left) / 2;

            // 1LL converts the expression to long long to prevent integer overflow
            long long sq = 1LL * mid * mid;

            if (sq == x) {
                return mid;
            }
            else if (sq > x) {
                right = mid - 1;
            }
            // If mid² is less than x,
            // mid is a possible answer
            else {

                // Store current valid answer
                ans = mid;
                left = mid + 1;
            }
        }
        return ans;
    }
};