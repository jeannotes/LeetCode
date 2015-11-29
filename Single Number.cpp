class Solution1 {
public:
//这是用hash表写的，纪念一下。独立的哦。
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> hash;
        int len=nums.size();
        
        for(int i=0;i<len;i++){
            hash[nums[i]]++;
        }
        for(int i=0;i<len;i++){
            if(hash[nums[i]]!=2){
                return nums[i];
            }
        }
    }
};

class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size();i++){
            res^=nums[i];
        }//0与任何数字异或还为他本身，再次异或又是0.
        return res;
    }
};
