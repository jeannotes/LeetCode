class Solution {
//https://leetcode.com/problems/roman-to-integer/
public:
    int romanToInt(string s) {
        int res=RomsToInt(s[0]);
        for(int i=1;i<s.length();i++){
            if(RomsToInt(s[i-1])<RomsToInt(s[i])){
                res+=RomsToInt(s[i])-2*RomsToInt(s[i-1]);
                //一开始加上了一个，由于计算法则，本身也要减去一个，所以是两倍
            }else{
                res+=RomsToInt(s[i]);
            }
        }
        return res;
    }
    
    int RomsToInt(char ch){
        int res=0;
        switch(ch){
            case 'I':   res=1;break;
            case 'V':   res=5;break;
            case 'X':   res=10;break;
            case 'L':   res=50;break;
            case 'C':   res=100;break;
            case 'D':   res=500;break;
            case 'M':   res=1000;break;
        }
        return res;
    }
};
// 颇有疑问，罗马字符技术规则不了解
