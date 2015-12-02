
class Solution {
//https://leetcode.com/problems/palindrome-number/
public:
    bool isPalindrome(int x) {
        if(x<0)     return false;
        if(x<10)    return true;
        int div=1;
        for(;x/div>=10;div=div*10);//这个分号不能少
        
        while(x!=0){
            int left=x/div;
            int right=x%10;
            if(left!=right)     return false;
            x=(x%div)/10;
            div=div/100;
        }
        return true;
    }
};
