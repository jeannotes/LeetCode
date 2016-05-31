
class Solution {
//https://leetcode.com/problems/palindrome-number/
public:
    bool isPalindrome(int x) {
        if(x<0)     return false;
        if(x<10)    return true;
        int div=1;
        for(;x/div>=10;div=div*10);//这个分号不能少  万一出现 100 10的情况
        
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
//  for(;x/div>=10;div=div*10);//这个分号不能少  
// 这个地方要用除，防止溢出
//还是考虑不够周到，总感觉前面几个题目不能通过的啊，上午三题全部做错，晚上还是全部出错啊，全部做错
// 哎，还是出错啊
// 注意这个 div=div/100;  这边容易除以0，right可能等于0
// 就是前面的这三道题，我从来没有AC过得，丫丫
