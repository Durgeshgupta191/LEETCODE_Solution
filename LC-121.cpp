class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int minBuy = INT_MAX;
        int maxPro = 0;

        for(int i = 0; i < prices.size(); i++) {

            // Calculate profit if sold today
            maxPro = max(maxPro, prices[i] - minBuy);

            // Update minimum buying price
            minBuy = min(minBuy, prices[i]);
        }

        return maxPro;
    }
};