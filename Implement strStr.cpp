class Solution {
//https://leetcode.com/problems/implement-strstr/
public:
    int strStr(string haystack, string needle) {
        
        if(needle.length()<1){
            return 0;
        }
        
        int length1=haystack.length();
        int length2=needle.length();
        int i,j;
        for(i=0;i<=length1-length2;i++){
            if(haystack[i]==needle[0]){
                for(j=0;j<length2;j++){
                    if(haystack[i+j]!=needle[j]){
                        break;
                    }
                }
                if(j==length2){
                    
                    return i;
                }
            }
        }
        return -1;
    }
};
