class Solution {
public:
    vector<string> res; 
    unordered_set<string> u_set;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
       u_set =  unordered_set<string> (wordDict.begin(), wordDict.end());
        wordBreakHelper(s, 0, "");
        return res;
    
    }

    void wordBreakHelper(string s, int index, string cur) {
        if(index == s.size()){
            res.push_back(cur);
            return;
        }

        for(int i=index; i<s.size(); i++){
            string tt = s.substr(index, i-index+1);
            if(u_set.find(tt) != u_set.end()){
                wordBreakHelper(s, i+1, 
                                cur.empty()? (tt): (cur+" "+tt));
            }
        }
    }
};
