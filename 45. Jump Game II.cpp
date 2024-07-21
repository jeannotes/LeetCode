class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<=1) return 0;
        int curmax=0, end=0, ans=0;

        for(int i=0;i<nums.size()-1;i++){
            curmax = max(curmax, nums[i]+i);
            if(i==end){
                end=curmax;
                ans++;
            }
        }
        return ans;

    }
};
//比较典型的贪心。维护一个区间，区间表示第i步所能到达的索引范围。
//递推的方法为：每次都遍历一遍当前区间内的所有元素，从一个元素出发的最远可达距离是index+array[index]，
//那么下一个区间的左端点就是当前区间的右端点+1，
//下一个区间的右端点就是当前区间的max(index+array[index])，以此类推，直到区间包含了终点，统计当前步数即可。
//还是得，爱心，还行啊
