class Solution {
public:
//https://leetcode.com/problems/letter-combinations-of-a-phone-number/
    vector<string> letterCombinations(string digits) {
        string table[]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};//  (number:2-9)==(0-7)
        vector<string> result;
        if(digits.empty()){     //考虑输入为空的情况
            return result;   
        }
        string s;//缓存
        combinationHelper(table,digits,0,s,result);//table[]不对
        return result;
    }
    
    void combinationHelper(string table[],string &digits,int start,string &s,vector<string> &result){
        if(start==digits.size()){
            result.push_back(s);
            return;
        }//限制条件
        
        int i=digits[start]-'2';
        if(i<0||i>7){//这一段没有也没事
            return;//本来以为这句是没啥用的，只是后面start不断+1,会导致溢出，所以有用。
        }
        
        for(int j=0;j<table[i].size();j++){
            s.push_back(table[i][j]);
            combinationHelper(table,digits,start+1,s,result);
            s.pop_back();
        }
    }
};
