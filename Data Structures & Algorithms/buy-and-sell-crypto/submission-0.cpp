class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProxit = 0;
        for (int i = 0; i < prices.size(); ++i) {
            for (int j = i + 1; j < prices.size(); ++j) {
                int potentialProfit = prices[j] - prices[i];
                if (maxProxit < potentialProfit) {
                    maxProxit = potentialProfit;
                }
            }
        }
        return maxProxit;
        
    }
};
