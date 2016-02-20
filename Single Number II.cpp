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
        int res=0;
        for(int i=0;i<32;i++){
            //它是一位一位的操作,当i=3的时候，count[j]<<3，右移3位，使得能够计算第三位的总出现数。当然最终判断是否是3的倍数
            for(int j=0;j<nums.size();j++){
                if(nums[j]>>i&1){
                    count[i]++;
                }
            }
            res |= (count[i]%3)<<i;
        }
        return res;
    }
};
/* &是按位与 && 是逻辑运算符，返回为bool值 */
