class Solution {
public:
//https://leetcode.com/problems/count-and-say/
string countAndSay(int n) {
    //return solution1(n);        //recursive
    return solution2(n);        //iterative
}
private:
string solution1(int n){
    if(n == 2) return "11";
    if(n == 1) return "1";
    string s = solution1(n - 1);
    int count = 1, i;
    char c = s[0];
    string ns;
    for(i = 1; i < s.length(); i++){
        if(s[i] == c) count++;
        else{
            ns += char('0'+count);
            ns += c;
            c = s[i];
            count = 1;
        }
    }
    //考虑最后一个字符
    ns += char('0'+count);
    ns += c;
    
    return ns;

}
string solution2(int n){
    if(n-- == 1) return "1";
    string cur, pre = "11";
    while(--n){
        int count = 1, i;
        char c = pre[0];
        for(i = 1; i < pre.length(); i++){
            if(pre[i] == c) count++;
            else{
                cur += char('0'+count);
                cur += c;
                c = pre[i];
                count = 1;
            }
        }
        if(i == pre.length()){
            cur += char('0'+count);
            cur += c;
        }
        pre = cur;
        cur = "";
    }
    return pre;
}
};
//write by myself
class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        if(n==2)
            return "11";
        string tem=countAndSay(n-1);
        int count=1,i=0,len=tem.length(),j=0;
        char c=tem[0];
        string res;
        while(i<=len-1){
            count=0;
            c=tem[i];
            for(j=i;j<len;j++){
                if(tem[j]==c)
                    count++;
                else
                    break;
            }
            res+=char(count+'0');
            res+=c;
            i=j;
        }
        return res;
    }
};
//这一遍做出来了
//这一遍做出来了
