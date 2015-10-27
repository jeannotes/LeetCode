class Solution {
public:
    string simplifyPath(string path) {
        int len=path.length();
        int i=0;//代表具体位置
        
        vector<string> result;
        while(i<len){
            //去掉所有的////
            while( path[i]=='/') i++;       //  这个地方不加“ i< len”是没事的，因为开头就已经判断
            if(i==len)    break;
            
            //找出接下来的字符
            string temp;
            while(i<len && path[i]!='/'){   //  这个地方不加“ i< len”不行，因为上面i++可能会导致溢出
                temp.push_back(path[i++]);
            }
            if(temp==".")   continue;
            if(temp=="..") {
                if(!result.empty()){
                    result.pop_back();
                }
            }
            else {
                result.push_back(temp);
            }
        }
        
        //程序往下执行说明有数据
        string final;
        
        if(result.empty()){
            return "/";
        }
        for(int i=0;i<result.size();i++){
            final.append("/");
            final.append(result[i]);
        }
        return final;
    }
};
