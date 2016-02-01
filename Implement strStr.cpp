class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length()<1)
            return 0;
        int len1=haystack.length(),len2=needle.length();
        for(int i=0;i<=len1-len2;i++){
            if(haystack[i]==needle[0]){
                int j=0;
                for(;j<len2;j++){
                    if(needle[j]!=haystack[i+j])
                        break;
                }
                if(j==len2)
                    return i;
            }
        }
        return -1;
    }
};
