class Solution {
public:
//https://leetcode.com/problems/palindrome-partitioning/
    vector<vector<string>> partition(string s) {
        vector<string> tmp;
        vector< vector<string> > result;
        int length=s.length();
        if(length==0){
            return result;
        }
        partitionHelper(0,s,tmp,result);
        return result;
    }
    
    void partitionHelper(int start,string &s,vector<string> &tmp,vector< vector<string> > &result){
        if(start==s.length()){
            result.push_back(tmp);
            return;
        }
        
        for(int i=start;i<s.length();i++){
            if(isPalindrome(start,i,s)){
                tmp.push_back(s.substr(start, i-start+1) );//左闭右开
                partitionHelper(i+1,s,tmp,result);
                tmp.pop_back();
            }
        }
    }
    
    bool isPalindrome(int start,int end,string &s){
        int mid=(start+end)/2;
        int i=start,j=end;
        while(i<=j){
            if(s[i++]!=s[j--]){
                return false;
            }
        }
        return true;
    }
};
