class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>res;
        int len=words.size(),i=0;
        while(i<len){
            int rowlen=0,j=i;
            //找能够放进去几个
            while(j<len&&words[j].length()+rowlen<=maxWidth){
                rowlen+=(words[j++].length()+1);
            }//i---j  此时的j是不行的，另外还多一个字符空格  j-1 就是有多少符合的
            
            if(j-i==1){//处理单个字符
                addSpace(words[i],maxWidth-(rowlen-1));
                res.push_back(words[i]);
                i=j;continue;
            }
            
            int charaLen=rowlen-(j-i);//当前有多少个字符
            int meanSpace=j<len?  (maxWidth-charaLen)/(j-i-1) : 1;//只要是最后一行，无论有多少个字符串，间隙都是1
            int leftSpace=j<len?  (maxWidth-charaLen)%(j-i-1) : (maxWidth-(rowlen-1)); 
            //如果是最后一行，括号里面减去1是因为在最开始多加了1，反正最后一个字符距离倒数第二个就一个字符。
            
            string tmp;
            for(int k=i;k<j-1;k++){//j不符合要求
                tmp+=words[k];
                addSpace(tmp,meanSpace);
                if(j<len&&leftSpace>0){
                    tmp.push_back(' ');leftSpace--;
                }
            }//接下来是最后一个单词
            
            tmp+=words[j-1];
            if(leftSpace>0)     addSpace(tmp,leftSpace);
            res.push_back(tmp);
            i=j;
            
        }
        return res;
    }
    
    void addSpace(string &s,int count){
        for(int i=1;i<=count;i++){
            s.push_back(' ');
        }
    }
};