class Solution1 {
public:
//第一种解法：hash表
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> hash;
        int len=nums.size();
        
        for(int i=0;i<len;i++){
            hash[nums[i]]++;
        }
        for(int i=0;i<len;i++){
            if(hash[nums[i]]!=3){
                return nums[i];
            }
        }
    }
};

class Solution2 {
public:
//第二种解法：位操作法
    int singleNumber(vector<int>& nums) {
        int count[32]={0};
        int result=0;
        for(int i=0;i<32;i++){
            for(int j=0;j<nums.size();j++){
                if(nums[j]>>i&1){
                    //它是一位一位的操作,当i=3的时候，count[j]<<3，右移3位，使得能够计算第三位的总出现数。当然最终判断是否是3的倍数
                    count[i]++;
                }
            }
            result |= (count[i]%3)<<i;//一开始卡在这里，没能够想到 如果一个数单独出现1次，那么一定是每一位都不是3的倍数，所以
            //count[i]%3<<i才有意义
        }
        return result;
    }
};
