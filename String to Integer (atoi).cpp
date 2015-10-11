class Solution {
public:
//https://leetcode.com/problems/string-to-integer-atoi/
    int myAtoi(string str) {
        int result=0;
        
        int i=0,sign=1;
        int length=str.length();
        
        while(str[i]==' '){
            i++;
        }//找到非空值
        
        if(str[i]=='+'){
            sign=1;
            i++;
        }else if(str[i]=='-'){//完美解决没有符号问题
            sign=-1;
            i++;
        }
        
        while(   '0'<=str[i]&&str[i]<='9'   ){
            if(result>INT_MAX/10){
                return sign==1?INT_MAX:INT_MIN;
            }
            if(result==INT_MAX/10){
                if(sign==1){
                    return str[i]>'7'?(INT_MAX):(result*10+(str[i]-'0'));
                }
                if(sign==-1){
                    return str[i]>='8'?(INT_MIN):-(result*10+(str[i]-'0'));
                }
            }
            result=result*10+(str[i]-'0');
            i++;
        }
        
        return result*sign;
    }
};
