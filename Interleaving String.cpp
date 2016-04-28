class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        /*
        match[i][j]  means  s1[0...i-1] s2[0...j-1]  是否匹配 s3[0...i+j-1]
        
        match[i][j]=(s1[i-1]==s3[i+j-1])&&match[i-1][j]||
                    (s2[j-1]==s3[i+j-1])&&match[i][j-1])
        
        */
        if(s1.size()+s2.size()!=s3.size())
            return false;
        vector< vector<int> >match(s1.size()+1,vector<int>(s2.size()+1,false) );
        // match[size()+1][size()+1]
        match[0][0]=true;
        
        //初始化
        for(int i=1;i<=s1.size();i++){
            if(s1[i-1]==s3[i-1]){
                match[i][0]=true;
            }else{
                break;
            }
        }
        
        for(int i=1;i<=s2.size();i++){
            if(s2[i-1]==s3[i-1]){
                match[0][i]=true;
            }else{
                break;
            }
        }
        
        //初始化结束
        
        for(int i=1;i<=s1.size();i++){
            for(int j=1;j<=s2.size();j++){
                if(s1[i-1]==s3[i+j-1]){
                    match[i][j]=match[i-1][j];
                }
                if(s2[j-1]==s3[i+j-1]){
                    match[i][j]=match[i][j-1]||match[i][j];//这里要或以下，但是刚刚不需要。
                    //因为刚才是第一次，因为公式的原因，他是或的关系。
                }
            }
        }
        
        return match[s1.size()][s2.size()];
    }
};
//还是有一些不会
//就是不会
//做事做出来，只是还不是很懂啊
//  i，j  仅仅表示第i位，第j位能否组合成第i+j位。这是好题目啊
//  要看我的解释，非常到位 虽然一次AC
