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
class Solution2 {
public:
//--  更加通俗易懂，贪心法，只要后面一天比前面一天价格高，就卖。然后再买。
//最简单的算法
    int maxProfit(vector<int>& prices) {
		if (prices.empty()){
			return 0;
		}
		int ans=0;
		int prev=prices[0];
		for (int i=1;i<prices.size();i++){
			if (prices[i]>prev){
				ans+=prices[i]-prev;
				prev=prices[i];
			}else
				prev=prices[i];
		}
		return ans;
	}
};
// 感觉还不错啊
