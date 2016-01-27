class Solution {
    //https://segmentfault.com/a/1190000002651263
public:
    int jump(vector<int>& nums) {
        if(nums.empty()||nums.size()==1)
            return 0;
        int curEnd=0,curBegin=0,count=0;
        
        while(curEnd<nums.size()){
            int last=curEnd;
            for(int i=curBegin;i<=curEnd;i++){
                last=max(last,i+nums[i]);
                if(last>=nums.size()-1)
                    return count+1;//相当于是每次都在判断当前这个区间内最远距离
            }
            curBegin=curEnd+1;
            curEnd=last;
            count++;//didn't that kind understand
        }
        return count;
    }
};
//比较典型的贪心。维护一个区间，区间表示第i步所能到达的索引范围。
//递推的方法为：每次都遍历一遍当前区间内的所有元素，从一个元素出发的最远可达距离是index+array[index]，
//那么下一个区间的左端点就是当前区间的右端点+1，
//下一个区间的右端点就是当前区间的max(index+array[index])，以此类推，直到区间包含了终点，统计当前步数即可。
