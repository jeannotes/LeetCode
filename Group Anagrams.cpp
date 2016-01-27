class Solution1 {
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
// 有错误程序
class Solution2 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        if(strs.empty()||strs[0].empty())
            return res;
        map<string,int>group;
        int count=0;
        for(int i=0;i<strs.size();i++){
            string tem=strs[i];
            sort(tem.begin(),tem.end());
            if(group.find(tem)==group.end()){
                group[tem]=count;
                count++;
                res[group[tem]].push_back(strs[i]);
            }else
                res[group[tem]].push_back(strs[i]);
        }
        for(int i=0;i<res.size();i++){
            sort(res[i].begin(),res[i].end());
        }
        return res;
    }
};
