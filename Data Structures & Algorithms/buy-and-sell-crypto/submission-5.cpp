class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sellPrice {};
        int sellPriceIndex {};
        int potentialBuyPrice {};
        int buyPrice {};
        int profit {};
        if (prices.size() == 0) return profit;
        buyPrice = prices[0];
        potentialBuyPrice = buyPrice;
        for (int i = 1; i < prices.size(); i++) {
            if (potentialBuyPrice > prices[i]) {
                if (sellPriceIndex > i) {
                    buyPrice = prices[i];
                    potentialBuyPrice = prices[i];
                } else {
                    potentialBuyPrice = prices[i];
                }
            } 
             if (sellPrice - buyPrice <= prices[i] - potentialBuyPrice) {
                sellPrice = prices[i];
                sellPriceIndex = i;
                buyPrice = potentialBuyPrice;
            }
        }
        profit = sellPrice - buyPrice;
        return (profit > 0) ? profit : 0;
    }
};
 