class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //使用hash表
        vector<int>  last;
        map<int,int> hash_table;
        
        for(int i=0;i<nums.size();i++){
            if(hash_table.count(target-nums[i])==1){
                //查看减去的差值是否存在，因为题目说不会出现两个答案，所以只会等于1
                int n=hash_table[target-nums[i]];
                last.push_back(n+1);
                last.push_back(i+1);
                break;
            }
            if(hash_table.count(nums[i])==0){
                hash_table.insert(pair<int,int>(nums[i],i));//没有重复就输入到map中
                //1,1,2  在后面自然能够对第二个i进行处理
            }
            //如果判断target-nums[i]的if分支在后面，很容易遇到一个问题，
            //第一个进去3，target是6，刚刚进去3，然后6-3也在hash_table里面
            //直接退出
        }
        return last;
    }
};
