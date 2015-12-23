class Solution {
//https://leetcode.com/problems/length-of-last-word/
public:
    int lengthOfLastWord(string s) {
        if(s.empty())   return 0;
        //从后往前找第一个非" "的字符，如果没有，返回0
        int len=s.length();
        int j=len-1;
        while(j>=0&&s[j]==' ')   j--;
        if(j<0) return 0;
        for(int i=j;i>=0;i--){
            if(s[i]==' ')
                return j-i;
            if( s[i]!=' '&&i==0 )
                return j-i+1;
        }
        return 0;
    }
};
