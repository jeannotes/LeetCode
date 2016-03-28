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
//记住那个 k次交易的帖子，怎么设计
// 还是不会啊
// 对于i之后的理解应该是这样的，在之前我每次找最小值，然后一个一个比较
//现在我是从后面往前找，我每次都是先找最大值，然后减去当前值，之后在比较。这样才能代表某一天的收益，
//如果和之前一样，算的是从这一天开始的最大收益，现在无论怎样，都找最大值，减去当前的一天，再作比较
