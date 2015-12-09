class Solution {
//代码越来越简洁了
public:
    int strStr(string haystack, string needle) {
        if(needle.length()<1)
            return 0;
        int length1=haystack.length(),length2=needle.length();
        
        for(int i=0;i<=length1-length2;i++){
            if(haystack[i]==needle[0]){
                int j=0;
                for(;j<length2;j++){
                    if(needle[j]!=haystack[i+j])
                        break;
                }
                if(j==length2)
                    return i;
            }
        }
        return -1;
    }
};
