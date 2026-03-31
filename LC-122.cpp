//Leetcode 122: Best Time to Buy and Sell Stock II:


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0; // Total profit

        // Loop through the price array starting from the second day
        for (int i = 1; i < prices.size(); i++) {
            // If today's price is higher than yesterday's, we gain profit
            if (prices[i] > prices[i - 1]) {
                // Add the difference to total profit
                profit += prices[i] - prices[i - 1];
            }
            // Else we skip (i.e., no transaction if price drops or stays the same)
        }

        // Return total accumulated profit
        return profit;
    }
};
