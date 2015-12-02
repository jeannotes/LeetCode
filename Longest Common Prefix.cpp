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
        }//本题的一个疑问就是两个不同字母“a”,"b",为何输出的是a。
        return strs[0];
    }
};
