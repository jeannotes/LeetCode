class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        map<string,int>group;
        
        for(int i=0;i<strs.size();i++){
            string tem=strs[i];
            sort(tem.begin(),tem.end());
            if(group.find(tem)!=group.end()){
                res[group[tem]].push_back(strs[i]);
            }else{
                vector<string>temp;
                temp.push_back(strs[i]);
                res.push_back(temp);
                group[tem]=res.size()-1;
            }
        }
        for(int i=0;i<res.size();i++) 
            sort(res[i].begin(),res[i].end());
            
        return res;
    }
};
// 好题目，还有许多不会
// group[tem]=res.size()-1; 这个地方容易出错，因为hash表就是按照排序好的为底的
// 基本可以啦，一次AC啦。
