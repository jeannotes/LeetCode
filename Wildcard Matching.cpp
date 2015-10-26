class Solution {
public:
    bool isMatch(string s, string p) {
        char *ss=&s[0];char *pp=&p[0];
        
        char *start=NULL,*rs=NULL;
        
        while(*ss!='\0'){
            if(*ss==*pp||*pp=='?'){
                ss++;pp++;
                continue;
            }
            
            if(*pp=='*'){
                start=pp;
                pp++;//这个时候从下一位开始匹配，因为之前的p可以匹配0位的，1位的....
                rs=ss;
                continue;
            }
            
            //上面两种情况都不符合，那就让之前的*来匹配
            if(start!=nullptr){
                pp=start+1;
                ss=rs;//从第0位开始匹配
                rs++;
                continue;
            }
            
            return false;
        }
        
        while(*pp=='*'){
            pp++;
        }
        return *pp=='\0';
    }
};
