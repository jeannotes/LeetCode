class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length()<1)
            return 0;
        int len1=haystack.length(),len2=needle.length();
        for(int i=0;i<=len1-len2;i++){  //  这边不能写i<=haystack.length()-needle.length()  不知道为什么啊
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
    //bug_exist  我直接将break那个地方换成 return -1；不对，
    //这因为这一次循环不能够存在配对，下一次还可以，这就相当与一次不行，否决全部
};

/*
还是有问题，if(needle[j]!=haystack[i+j])
                        break;  这个地方不能直接返回 -1 还有可能下一次呢，i+1的情况还有可能
*/
