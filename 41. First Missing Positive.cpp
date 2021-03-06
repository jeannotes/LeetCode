class Solution {
//https://leetcode.com/problems/first-missing-positive/
public:
    int firstMissingPositive(vector<int>& nums) {
        // 1-a[0] 2-a[1] 3-a[2]   桶排序
        // 注意下面变换顺序
        if(nums.size()<1)   return 1;
        int num;
        for(int i=0;i<nums.size();i++){
            //if(nums[i]<=0)  continue;
            num=nums[i];
            while(num>0&&num<nums.size()&&num!=nums[num-1]){
                swap(nums[num-1],nums[i]);//  这边不能写nums[num]!=num+1 ，因为有可能导致越界啊
                num=nums[i];
            }//这边似乎就已经全部排列好了  可以 可以啊， 加油 加油啊 
        }
        //转换结束
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }//本来数组就2个数，[2,1],循环结束。
        return nums.size()+1;
    }
};
//bug-exist  在while那个循环那边  nums[i]>0&&nums[i]<=len 这两个条件没有看到
/*
if (tem>0&&tem<len){
			
		while (tem!=nums[tem-1]){
			//3 1 2
			swap(nums[i],nums[tem-1]);//2 1 3
			tem=nums[i];//1 2 3
		}
	}  中间循环部分不能写成这个，可能导致转换之后，出现负数，这个时候是一直在转换的，
//  这边不能写nums[num]!=num+1 ，因为有可能导致越界啊
*/
//终于会了一点
//  时间长点，不过能够做出来
//  忘记怎么做了，至于中间那部分，我倒是做出来了
// 竟然一下子做出来了，一下子成功啊，还是不会啊
int firstMissingPositive(vector<int>& nums) {
	if (nums.empty())
		return 1;
	int len = nums.size();
	for (int i = 0; i < nums.size();i++) {
		int tem = nums[i];
		while (tem>0&&tem<len&&nums[i]!=i+1){
			// 3 2 1   3
			swap(nums[i], nums[tem - 1]);tem = nums[i];
		}
	}
	for (int i = 0; i < nums.size();i++) {
		if (nums[i] != i + 1)
			return i + 1;
	}
	return nums.size() + 1;
}// for this situation,when it come to [1,1] ,it was a disaster
