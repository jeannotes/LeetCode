//本题只能买卖1次，从前到后
//一定还有动态规划的解法
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

