class Solution1 {
public:
//http://www.cnblogs.com/TenosDoIt/p/3662644.html
//https://leetcode.com/problems/permutations-ii/
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> >result;
        permuteHelper(0,nums,result);
        return result;
    }
   
    void permuteHelper(int start,vector<int>& nums,vector<vector<int> >&result){
        if(start==nums.size()){
            result.push_back(nums);
            return;
        }
        for(int i=start;i<nums.size();i++){
            if(i==start||!findDuplicates(nums[i],start,i,nums)){
                swap(nums[i],nums[start]);
                permuteHelper(start+1,nums,result);
                swap(nums[i],nums[start]);
            }
            //举例说明，1，1，2第一个选择1，没事，第一个选择不作要求，肯定不会相同，但是第二个
            //我就要比较了，因为start是1，第二个也是1，前面已经有去，再来一个就会重复。
            //就和数学里面排列组合一样。携程计算机语言就是第i次交换的时候，与后面第j个数字交换，得看[i...j-1]
            //是否还有重复数字，有重复不进行任何操作
        }
    }
    
    bool findDuplicates(int target,int start,int end,vector<int>& nums){
        for(int i=start;i<end;i++){
            if(nums[i]==target){
                return true;
            }
        }
        return false;
    }
};


class Solution2 {
public:
    //在算法1的基础上，当我们枚举第i个位置的元素时
    //，若要把后面第j个元素和i交换，则先要保证[i…j-1]范围内没有和位置j相同的元素。
    //有以下两种做法
    //（1）可以每次在需要交换时进行顺序查找；
    //（2）用哈希表来查重。具体见下面的代码。

    //注意不要误以为以下两种做法能够去重：
    //（1）最开始先对数组进行排序，以后每次交换时，只要保证当前要交换的元素和前一个元素不同，这种做法是错误的，虽然开始进行了排序，但是元素的交换会使数组再次变的无序
    //（2）每次进入递归函数permuteRecur时，对从当前索引开始的子数组排序，这种做法也是错误的，因为每次交换元素后，我们要恢复交换的元素，如果在递归函数内排序，就不能正确的恢复交换的元素。  
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> >result;
        if(nums.empty())
            return result;
        sort(nums.begin(),nums.end());
        
        permuteHelper(0,nums,result);
        return result;
    }
    
    void permuteHelper(int start,vector<int>& nums,vector<vector<int> >&result){
        if(start==nums.size()){
            result.push_back(nums);
            return;
        }
        unordered_set<int>map;
        for(int i=start;i<nums.size();i++){
            if( map.find(nums[i])==map.end() ){
                map.insert(nums[i]);
                swap(nums[i],nums[start]);
                permuteHelper(start+1,nums,result);
                swap(nums[i],nums[start]);
            }
        }
    }
};
