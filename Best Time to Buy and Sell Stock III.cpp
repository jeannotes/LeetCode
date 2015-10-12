class Solution {
public:
//http://liangjiabin.com/blog/2015/04/leetcode-best-time-to-buy-and-sell-stock.html
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2){
            return 0;
        }
        int n=prices.size();
        vector<int> preProfit(n,0);
        vector<int> postProfit(n,0);
        
        //从前往后
        int minPrice=prices[0];
        for(int i=1;i<=prices.size()-1;i++){
            minPrice=min(minPrice,prices[i]);
            preProfit[i]=max(preProfit[i-1],prices[i]-minPrice);
        }
        //从后往前
        int maxPrice=prices[n-1];
        for(int i=n-2;i>=0;i--){
            maxPrice=max(maxPrice,prices[i]);
            postProfit[i]=max(postProfit[i+1],maxPrice-prices[i]);
        }
        
        int maxProfit=0;
        for(int i=0;i<=preProfit.size()-1;i++){
            maxProfit=max(maxProfit,postProfit[i]+preProfit[i]);
        }
        
        return maxProfit;
    }
};
