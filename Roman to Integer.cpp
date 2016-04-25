class Solution {
//https://leetcode.com/problems/roman-to-integer/
public:
    int romanToInt(string s) {
    	if (s.empty())
    		return 0;
    	int res = 0;
    	for (int i = 0; i < s.size();i++) {
    		res += RomsToInt(s[i]);
    		if (i > 0 && RomsToInt(s[i]) > RomsToInt(s[i - 1]))
    			res = res - 2 * RomsToInt(s[i-1]);
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
// 颇有疑问
// 写了一个更加简单的代码
