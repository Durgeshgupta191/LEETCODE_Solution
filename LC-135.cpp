/* CANDY :   1.  ensure that every child must have at least one candy.
             2.  Children with a higher rating get more candies than their neighbors.
*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        // Step 1: Initialize a candies array with 1 candy for each child (minimum requirement)
        vector<int> candies(n, 1);

        // Step 2: Left to Right pass
        // Ensure that if the current child has a higher rating than the previous one,
        // they get more candies than the previous child
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Step 3: Right to Left pass
        // Ensure that if the current child has a higher rating than the next one,
        // they also get more candies than the next child.
        // Use max() to keep the larger value from both passes.
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        // Step 4: Sum up all the candies to find the minimum required
        int totCandy = 0;
        for (int i = 0; i < candies.size(); i++) {
            totCandy += candies[i];
        }

        // Return the total candies needed
        return totCandy;
    }
};
