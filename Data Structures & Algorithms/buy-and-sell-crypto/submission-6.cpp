class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int potentialBuyPrice {};
        int buyPrice {};
        int maxProfit {};
        if (prices.size() == 0) return maxProfit;
        buyPrice = prices[0];
        potentialBuyPrice = buyPrice;
        for (int i = 1; i < prices.size(); i++) {
            if (maxProfit < prices[i] - buyPrice) {
                maxProfit = prices[i] - buyPrice;
            } 
             if (buyPrice > prices[i]) {
                buyPrice = prices[i];
            }
        }
        return (maxProfit > 0) ? maxProfit : 0;
    }
};
 