class Solution {
public:
//https://leetcode.com/problems/word-break/
//http://blog.csdn.net/feliciafay/article/details/18999903
    bool wordBreak(string s, unordered_set<string>& dict) {
        if(s.empty())
            return true;
        vector <bool> B(s.size()+1,false);
        B[0]=true;//
        
        for(int i=0;i<s.size();i++){
            for(int j=i;j>=0;j--){
                if(dict.find(s.substr(j,i-j+1))!=dict.end()&&B[j]){
                    B[i+1]=true;break;
                }
                
            }
        }
        //从i=0开始，先判断s[0]在不在数组里面，如果B[0]设置为false就没有意义，以后不会成功
        //如果在里面，则表示B[1]=true，表示s[0]可以被数组分开
        //再继续，i=1,  j先是=1，先是找一下s[1]在不在，并且判断B[1],再判断s[0..1]在不在数组里面，并判断B[0]
        //与此类似 i=max, 
        //  s[max]存在数组中吗...B[max]表示前面max个能否被分割...
        //  s[max-1..max]存在数组中吗...B[max-1]能否被分割。
        //一开始没有把“break;”放在if函数里面，发现原因是：本break的功能是如果能够找到某一段的字符串，那就停止本次(里面)的循环
        //继而开始下一次(外面)的循环
        return B[s.size()];
    }
};
