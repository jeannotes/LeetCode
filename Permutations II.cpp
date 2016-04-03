class Solution {
public:
    //在算法1的基础上，当我们枚举第i个位置的元素时
    //，若要把后面第j个元素和i交换，则先要保证[i…j-1]范围内没有和位置j相同的元素。
    //有以下两种做法
    //（1）可以每次在需要交换时进行顺序查找；
    //（2）用哈希表来查重。具体见下面的代码。

    //注意不要误以为以下两种做法能够去重：
    //（1）最开始先对数组进行排序，以后每次交换时，只要保证当前要交换的元素和前一个元素不同，
    //这种做法是错误的，虽然开始进行了排序，但是元素的交换会使数组再次变的无序
    //（2）每次进入递归函数permuteRecur时，对从当前索引开始的子数组排序，这种做法也是错误的，
    //因为每次交换元素后，我们要恢复交换的元素，如果在递归函数内排序，就不能正确的恢复交换的元素。  
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
                //实际上，这里的unorder_set只能定义在函数内部，因为如果放在最外面，1 1 1 2 下一次比较的时候1就不能放进去
                //放在里面，start+1的时候，如果相同的数字就不会放进去，函数内部连贯的
                map.insert(nums[i]);
                swap(nums[i],nums[start]);
                permuteHelper(start+1,nums,result);
                swap(nums[i],nums[start]);
            }
        }
    }
};
/*
if(i>start&&nums[i]==nums[i-1])
			continue;这个是不对的，因为每一次的变换使得数组再次变得无序啊 09010-09001-09100-09010
*/
//不会啊
