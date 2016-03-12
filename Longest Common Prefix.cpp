class Solution {
//https://leetcode.com/problems/longest-common-prefix/
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())    return "";
        for(int i=0;i<strs[0].size();i++){
            for(int j=1;j<strs.size();j++){
                if(strs[j][i]!=strs[0][i])
                    return strs[0].substr(0,i);
            }
        }//本题的一个输入两个不同字母“a”,"b",为何输出的是sunstr(0,0)，这个时候是空
        return strs[0];
    }
};
//题目意思不太清楚 还有不熟悉每个字符的大小
