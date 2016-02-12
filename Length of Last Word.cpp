class Solution {
//https://leetcode.com/problems/length-of-last-word/
public:
    int lengthOfLastWord(string s) {
        if(s.empty())
            return 0;
        int i=s.length()-1,count=0;
        while(i>=0&&s[i]==' ')
            i--;
        for(;i>=0;i--){
            if(s[i]!=' ')
                count++;
            else
                break;
        }
        return count;
    }
};
// bug-free
