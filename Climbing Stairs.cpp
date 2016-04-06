class Solution {
public:
//斐波那契数列，下一个数，要么之前一位的，要么之前两位的。
    int climbStairs(int n) {	//123
    	vector<int>res(n+1,1);
    	for (int i=2;i<=n;i++){
    		res[i]=res[i-1]+res[i-2];
    	}
    	return res[n];
    }
};
//不会
// 现在能够搞清楚为什么 sum[0]=1;sum[1]=1; 因为一开始作为初始条件，后面第二步要从sum[0]计算的
//基本可以，今晚不做leetcode啦，加油
