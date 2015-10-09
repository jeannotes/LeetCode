//本题三种解法，还有一种动态规划法，暂时不做。
//https://leetcode.com/problems/gas-station/
class Solution1 {
public:
//http://m4tiku.duapp.com/report?pid=18
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int startIndex=0;
        int sum=0;
        for(int i=0;i<=gas.size()-1;i++){
            sum=sum+(gas[i]-cost[i]);
            if(sum<0){
                startIndex=i+1;
                sum=0;
            }
        }
        //判断是不是到了末尾
        if(startIndex==gas.size()){
            return -1;
        }
        //从startIndex之后都没有问题，但是不知道，从结尾到startIndex是不是有问题。
        for(int i=0;i<startIndex;i++){
            //就相当于确定了后面，继续确定前面
            sum=sum+(gas[i]-cost[i]);
            if(sum<0){
                return -1;
            }
        }
        return startIndex;
    }
};
