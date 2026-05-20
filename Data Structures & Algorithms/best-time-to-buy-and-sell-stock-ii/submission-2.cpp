class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int profit = 0;

        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] > prices[i-1]) profit+= prices[i] - prices[i-1];
        }
        return profit;



        // prices.push_back(-1);

        // int low = 0;
        // int high = low;
        // int profit = 0;
        // bool executed = false;

        // while(high != prices.size() - 1)
        // {
        //     if(prices[high + 1] < prices[high])
        //     {
        //         profit += prices[high] - prices[low];
        //         low = high + 1;
        //         executed = true;
        //     }
        //     high++;
        // }
        // if(executed == false) { 
        //     profit = prices[high] - prices[low];
        // }
        // return profit;
        
    }
};