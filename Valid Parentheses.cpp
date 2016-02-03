class Solution {
public:
    bool isValid(string s) {
        if(s.empty())
            return false;
        int len=s.length();
        stack<char>stk;
        
        for(int i=0;i<len;i++){
            if(s[i]=='['||s[i]=='{'||s[i]=='('){
                stk.push(s[i]);
            }else{
                if(stk.empty()){
                    return false;
                }else if(stk.top()=='{'&&'}'==s[i]){
                    stk.pop();
                }else if(stk.top()=='['&&']'==s[i]){
                    stk.pop();
                }else if(stk.top()=='('&&')'==s[i]){
                    stk.pop();
                }else
                    return false;
            }
        }
        return stk.empty();//假如出现“（）”,没有这句话，就会没有数值输出
    }
};

class Solution {
public:
    bool isValid(string s) {
        if(s.empty())
            return true;
        stack<char>res;
        if(s.length()%2!=0)
            return false;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
                res.push(s[i]);
            else{
                if(res.empty())
                    return false;
                else{
                    char tem=res.top();res.pop();
                    if(tem=='('&&s[i]==')'||tem=='['&&s[i]==']'||tem=='{'&&s[i]=='}')
                        continue;
                    else
                        return false;
                }
            }
        }
        return res.empty();//防止出现 “((”的情况
    }
};
