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
 
 //dp[i] 表示[0...i]内最大值，则dp[i+1]=max(dp[i],prices[i+1]-min)
 //min是[0...i]内的最小值

//3比1更加简洁。
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()){
            return 0;
        }
        int minPrice=prices[0],maxProfit=0;
        for(int i=1;i<prices.size();i++){
            minPrice=min(minPrice,prices[i]);
            maxProfit=max(maxProfit,prices[i]-minPrice);
        }
        
        return maxProfit;
    }
};
// 有一些小瑕疵，我是用的最后一个方法，只是不太完美
//还不错呢
