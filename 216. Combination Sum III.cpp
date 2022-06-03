class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;
    vector<vector<int>> combinationSum3(int k, int n) {
        combinationSum_h(k, 
                         1,
                         n);
        return res;
    }

    void combinationSum_h(int k, 
                          int start,
                          int n) {
        if(temp.size()==k and n==0){
            res.push_back(temp);return;
        }
        if(start>9||n<0){
            return;
        }
        for(int i=start;i<10;i++){
            if(n-i<0) return;
            temp.push_back(i);
            combinationSum_h(k, 
                           i+1,
                           n-i);
            temp.pop_back();
        }
    }
};
