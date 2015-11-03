class Solution {
public:
    int romanToInt(string s) {

        int res=RomsToInt(s[0]);
        for(int i=1;i<s.length();i++){
            if( RomsToInt(s[i-1]) < RomsToInt(s[i]) ){
                res+=RomsToInt(s[i])-2*RomsToInt(s[i-1]);//因为之前的字符代表数字比当前的大，首先要把它减掉，又因为在前面已经加上数字，不能重复，所以减掉2倍。
            }else{
                res+=RomsToInt(s[i]);
            }
        }
        return res;
    }
    
    int RomsToInt(char ch){
        int d=0;
        switch(ch){
            case 'I':  
                d = 1;  
                break;  
            case 'V':  
                d = 5;  
                break;  
            case 'X':  
                d = 10;  
                break;  
            case 'L':  
                d = 50;  
                break;  
            case 'C':  
                d = 100;  
                break;  
            case 'D':  
                d = 500;  
                break;  
            case 'M':  
                d = 1000;  
                break;  
        }
        return d;
    }
};
