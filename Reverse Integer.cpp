class Solution {
public:
//https://leetcode.com/problems/reverse-integer/
    int reverse(int x) {
        if(x<0){
            return x==INT_MIN?0:-reverse(-x);
        }
        
        int y=0,res=0;
        // 123--321
        while(x>0){
            if(res>INT_MAX/10)
                return 0;
            if(res==INT_MAX&&(x%10>7))
                return 0;
            res=res*10+x%10;
            x=x/10;
        }
        return res;
    }
};
