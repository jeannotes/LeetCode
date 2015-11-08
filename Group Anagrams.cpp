class Solution {
//https://leetcode.com/problems/anagrams/
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> >res;
        map<string,int>m;
        for(int i=0;i<strs.size();i++){
            string word=strs[i];
            sort(word.begin(),word.end());
            if(m.find(word)!=m.end()){
                res[m[word]].push_back(strs[i]);
            }else{//没有出现过,就进入res这个动态数组，并且m[word]的数值赋值为当前数组大小
                vector<string> tmp;
                tmp.push_back(strs[i]);
                res.push_back(tmp);
                m[word]=res.size()-1;
            }
        }
        
        for(int i=0;i<res.size();i++){
            sort(res[i].begin(),res[i].end());
        }
        return res;
    }

};
