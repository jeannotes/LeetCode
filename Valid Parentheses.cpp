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
