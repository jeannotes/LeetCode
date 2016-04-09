class Solution {
public:
    string simplifyPath(string path) {
        vector<string>result;
        int len=path.length(),i=0;
        
        while(i<len){
            while(i<len&&path[i]=='/')
                i++;
            
            if(i==len)
                break;
            
            string tmp;
            while(i<len&&path[i]!='/')
                tmp+=path[i++];
            
            if(tmp==".")
                continue;
            else if(tmp==".."){
                if(!result.empty())
                    result.pop_back();
            }
            else
                result.push_back(tmp);
        }
        
        string res;
        if(result.empty())
            return "/";
        for(int i=0;i<result.size();i++){
            res+='/';
            res+=result[i];
        }
        
        return res;
    } 
};
//不会，今晚心不在焉
//记好，string tmp是string，if(tmp==".")  中应该是双引号，不是单引号
//还是的双引号的问题，还是有一点小瑕疵，不过很好啦，加油。
//要去见图书馆老师了。好紧张啊。
//一次通过
//  string数组为空时候，这种情况没有考虑到  还可以
// 效果还可以啊
