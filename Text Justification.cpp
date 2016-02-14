class Solution {
    //https://leetcode.com/submissions/detail/50523961/
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>res;
        int len=words.size(),i=0;
        while(i<len){
            int rowlen=0,j=i;
            //找能够放进去几个
            while(j<len&&words[j].length()+rowlen<=maxWidth){//之所以这么写，是考虑到最后一个没有空格
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
            //这里指的是所有的单词都是最后一行
            
            string tmp;
            for(int k=i;k<j-1;k++){//j不符合要求
                tmp+=words[k];
                addSpace(tmp,meanSpace);
                if(j<len&&leftSpace>0){
                    tmp.push_back(' ');leftSpace--;//j<len 这个条件不可少，加入是最后一行，而且j-i大于1，
                    //那么这之间是不需要增加空格,因为全部为1，已经算进去了
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
//rowlen+=(words[j++].length()+1);  这个地方没有加1，很多细节地方还不到位
