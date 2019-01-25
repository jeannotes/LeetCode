class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()||s.size()==0)
            return 0;
        map<char,int>map;
        int res=0;
        // a b c a
        for(int i=0,j=0;i<s.size();i++){
            if(map.find(s[i])!=map.end()){
                j=max(j,map[s[i]]+1);
/*
abba, j means next first single character
*/
                // j= map[s[i]]+1 ; //false code
            }
            map[s[i]]=i;
            res=max(res,i-j+1);
        }
        return res;
    }
};
/*
更正，这里，如果不使用ｍａｘ比较ｊ，那么就会把过去的某一个值给考虑进去了．比如说第一个ａ．
从一开始，累计到第二个ｂ，这个没有问题，但是后面再次遇到ａ，那么就会设置ｊ＝１，此时发生错误
*/
