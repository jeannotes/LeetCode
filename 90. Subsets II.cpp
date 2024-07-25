class Solution {
public:
    vector<vector<int>> res;
    vector<int> tem;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        res.push_back(tem);
        subsetsHelper(nums, 0);
        return res;
    }
    void subsetsHelper(vector<int>& nums, int start) {
        if(start >= nums.size()) return;
        unordered_set<int> u_st;
        for(int i=start; i<nums.size(); i++){
            if(u_st.find(nums[i]) == u_st.end()){
                u_st.insert(nums[i]);
                tem.push_back(nums[i]);
                res.push_back(tem);
                subsetsHelper(nums, i+1);
                tem.pop_back();
            }
            
        }
    }
};
