class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size());

        for(int i=0; i<s.size();i++){
            for(int j=0; j<=i; j++){
                string tem = s.substr(j, i-j+1);
                if(  (j<=0 || dp[j-1])
                    && (std::find(wordDict.begin(), wordDict.end(), tem) != wordDict.end())
                ){
                    dp[i]=true;
                }
            }
        }
        return dp[s.size()-1];
    }
};
