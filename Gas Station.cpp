//本题的集中解法本质上都一样。
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


class Solution2 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum=0,start,total=0;
        for(int i=0;i<gas.size();i++){
            sum=sum+gas[i]-cost[i];
            total=total+gas[i]-cost[i];
            if(sum<0){
                sum=0;
                start=i+1;//找到开始节点
            }
        }
        
        return total>=0?start:-1;//一定是大于等于
    }
};
//这道题首先是用的贪心算法，有几点需要注意：
//优先选择所有加起来，sum>0的。如果能够保证从某一点到最后，
//sum一直大于0，说明从这个点到最后一个点没问题，
//但这个时候，需要注意的是未必从前面能够走到index这个点，所以返回头继续判断
//，但升级版的程序就很简短，total一直做的工作就是累加
//不过需要证明一圈下来sum>0，一定存在某一个解。
//第一种：
//假设从0到n-1，从某点a,b,c,....,a，a不能反悔，恰好停留在b，然后b不能到c，一切很巧，
//sum[gas[a...b]]<sum[cost[a...b],sum[gas[b...c]]<sum[cost[b...c].....sum[gas[p...a]]<sum[cost[p...a]
//sum[gas[a...b]]+sum[gas[b...c]]+sum[gas[p...a]]<sum[cost[a...b]+sum[cost[b...c]+sum[cost[p...a]
//即  c*sum[gas]<c*sum[cost]，与原文矛盾
//第二种
//s1,s2,....sn-1能构成，这里sj代表gai[i]-cost[i]
//s1+s2+....+sn-1>0,那么存在某个s，使得s>   -1(s1+s2+....+sj-1)+ (-1)(sj+1+....+sn-1)
//也可以是连续的两项，都可以，即只是存在某一个解
//

//另外，某些所谓的动态规划其实和这种思路差不多。还需要证明的就是，从a点恰好到b点，
//但不能到达下一个点，那么a到b任何一个点都不能到达b的下一个点
//证明：从a到a与b之间任何一点 gas[i]-cost[i]都是大于0的，不然不能到达，
//那么从这一点到b下一点一定是负，不然加起来就是正，前面已经是正数，加起来是负数，那么后面一定是负数。就是这么证明。


//第二种方法其实本质上就是第一种方法的变形版本，只不过使用了total记录最后一点能否运行
//还是第二种方法好啊，不会做
