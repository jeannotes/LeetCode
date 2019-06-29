class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty())
            return 0;
        stack<int>res;
        int count=0,start=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
                res.push(i);
            else{
                if(res.empty())
                    start=0;// 这个地方很重要，如果单独出现‘）’，就需要判断
                else{
                    int tem=res.top();res.pop();
                    if(res.empty()){
                        start+=i-tem+1;//他的意思是找最长的一段括号，如果中间有一对间隔的，再隔了一个，自然start=0
                        count=max(count,start);
                    }else{
                        count=max(count,i-res.top());// hard part
                    }
                }
            }
        }
        return count;
    }
//注意体会两种特殊情况 "()()" "(())"
//出错根源在于"(())"  在res出栈后，如果不是空的，start+=i-tem+1; 这样会多加2
// 不会了啊，稍微会了一丢丢
