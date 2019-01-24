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
