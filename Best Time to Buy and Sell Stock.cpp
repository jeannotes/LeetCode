//本题只能买卖1次，从前到后
//写出了两种解法。
class Solution1 {
public:
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
    int maxProfit(vector<int>& prices) {
        
        int ans=0;
        if(prices.empty()){
            return 0;
        }
        int low=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]<low){
                low=prices[i];
            }else if(prices[i]-low>ans){
                ans=prices[i]-low;
            }
        }
        return ans;
    }
};

 class Solution2 {
 public:
     int maxProfit(vector<int> &prices) {
         int length=prices.size();
         if(length<=1){
             return 0;
         }
         vector<int> dp(length,0);
         int min=prices[0];
         for(int i=1;i<length;i++){
             if(prices[i]<=min){
                 min=prices[i];
             }
             dp[i]=max(  dp[i-1],prices[i]-min   );
         }
         sort(dp.begin(),dp.end());
         return dp.back();
     }
 };
 
 //dp[i] 表示[0...i]内最大值，则dp[i+1]=max(dp[i],prices[i+1]-min)
 //min是[0...i]内的最小值
