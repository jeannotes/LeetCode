class Solution {
public:
    string simplifyPath(string path) {
        vector<string>result;
        int len=path.length(),i=0;
        
        while(i<len){
            while(i<len&&path[i]=='/'){
                i++;
            }
            if(i==len)
                break;
            
            string tmp;
            while(i<len&&path[i]!='/'){
                tmp+=path[i++];
            }
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
