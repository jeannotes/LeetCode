class Solution {
    //http://www.cnblogs.com/TenosDoIt/p/3461301.html
public:
    string minWindow(string s, string t) {
        int lens=s.length(),lent=t.length();
        int number_in_t[256]={0};
        int number_found_in_t[256]={0};
        
        //初始化
        for(int i=0;i<lent;i++){
            number_in_t[t[i]]++;
        }
        
        int hasFound=0;
        int winStart=-1,winEnd=lens;
        
        //start 和i 一起扫描
        for(int i=0,start=0;i<lens;i++){
            if(number_in_t[s[i]]!=0){
                //s中的字符在t中存在
                number_found_in_t[s[i]]++;
                if(number_found_in_t[s[i]]<=number_in_t[s[i]])  hasFound++;
                //这句话是确保当前的字符不超过t字符串里面字符的个数
                if(hasFound==lent){//找到一个窗口
                    while(number_in_t[s[start]]==0 || number_found_in_t[s[start]]>number_in_t[s[start]]){
                        if(number_in_t[s[start]]!=0)    number_found_in_t[s[start]]--;//如果不剪掉，那么不能准确判断出现多少次
                        start++;
                    }
                    if(winEnd-winStart>i-start){//考虑一下这边+1 还是 -1 的情况
                        winEnd=i;winStart=start;
                    }
                    //这个时候以start开头的字符仅仅出现1次，减掉就可以满足下一个条件
                    
                    number_found_in_t[s[start]]--;//这是为了让刚刚第一个只出现一次的字符变成0，相应的hasFound也要减去1，其余不变
                    start++;hasFound--;
                }/**/
            }
        }
        return winStart!=-1? s.substr(winStart,winEnd-winStart+1):"";
    }
};
