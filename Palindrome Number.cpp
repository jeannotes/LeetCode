class Solution {
//https://leetcode.com/problems/palindrome-number/
public:
    bool isPalindrome(int x) {
        if(x<0)     return false;
        if(x<10)    return true;
        int div;
        for (div=1; (x/div) >= 10; div*=10 );
        
        while(x!=0){
            int left=x/div;
            int right=x%10;
            if(left!=right)     return false;
            x=(x%div)/10;//去除两端数字
            div=div/100;
        }
        return true;
    }
};
//R. City - Locked Away ft. Adam Levine 
//R. City - Locked Away ft. Adam Levine    連詩雅 Shiga Lin – 大了一歲 (Official Music Video)
