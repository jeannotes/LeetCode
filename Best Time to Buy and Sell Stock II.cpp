class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //贪心法，只要后面一天比前面一天价格高，就卖。然后再买。
        //最简单的算法
        if(prices.empty()){
            return 0;
        }
        
        int sum=0;
        for(int i=1;i<=prices.size()-1;i++){
            if(prices[i]>prices[i-1]){
                sum=sum+prices[i]-prices[i-1];
            }
        }
        
        return sum;
    }
};
