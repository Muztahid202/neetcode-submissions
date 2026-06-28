class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int buyPrice = 1000000;
        for(int i = 1; i < prices.size(); i++){
            buyPrice = min(buyPrice, prices[i-1]);
            maxProfit = max(maxProfit, prices[i]-buyPrice);
        }
        return maxProfit;
    }
};
