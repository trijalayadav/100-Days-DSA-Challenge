class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int mini = prices[0];
        int profit = 0;
        int n = prices.size();
        for (int i = 1; i < n; i++)
        {
            int diff = prices[i] - mini;
            profit = max(profit, diff);
            mini = min(mini, prices[i]);
        }
        return profit;

        // int n=prices.size(),maxProfit=INT_MIN,min=INT_MAX;
        // for(int i=0;i<n;i++){
        //     if(prices[i]<min){
        //         min=prices[i];
        //     }
        //     if(prices[i]>maxProfit){
        //         maxProfit=max(maxProfit,prices[i]-min);
        //     }
        // }
        // if(maxProfit<=0){
        //     return 0;
        // }
        // return maxProfit;
    }
};