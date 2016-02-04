class Solution {
//https://leetcode.com/problems/substring-with-concatenation-of-all-words/
//本题主要还是使用滑块法，就是从左往右依次滑动，然后检查这个位置是否存在
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> res;
        if(L.empty())   return res;
        int totalWords=L.size();
        int wordSize=L[0].size();
        int totalLen=wordSize*totalWords;
        if(S.size()<totalLen)   return res;//s自身字符串没有给出的表里面的总和字符数目多，没有任何输出
        unordered_map<string,int> wordCount;
        for(int i=0;i<L.size();i++){
            wordCount[L[i]]++;
        }
        
        for(int i=0;i<=S.size()-totalLen;i++){
            if(checkSubstring( S , i , wordCount , wordSize , totalWords))
                res.push_back(i);
        }
        return res;
    }
    
    bool checkSubstring(string &S,int start,unordered_map<string,int>&wordCount,int wordSize,int totalWords){
        if(S.size()-start+1<totalWords*wordSize)    return false;
        unordered_map<string,int> wordFound;
        
        for(int i=0;i<totalWords;i++){
            string tmp=S.substr(start+i*wordSize,wordSize); 
            if(  !wordCount.count(tmp)    )
                return false;//首先一开始我找的wordSize个字符如果不是hash表里面的直接返回
            wordFound[tmp]++;                                             
            if( wordFound[tmp] > wordCount[tmp] )   return false;                                          
        }
        return true;
    }
    
};


class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordSize=words[0].length();
        int totalWords=words.size();
        int totalLen=wordSize*totalWords;
        unordered_map<string,int>wordCount;
        vector<int>res;
        if(s.length()<totalLen)
            return res;
        for(int i=0;i<words.size();i++){
            wordCount[words[i]]++;
        }
        
        for(int i=0;i<=s.length()-totalLen;i++){
            if(check(i,words,s,wordCount,wordSize,totalWords,totalLen))
                res.push_back(i);
        }
        return res;
    }
    
    bool check(int start,vector<string>& words,string &s,unordered_map<string,int>wordCount,
            int wordSize,int totalWords,int totalLen){
        if(s.length()-start<totalLen)
            return false;
        unordered_map<string,int> wordFound;
        for(int i=0;i<totalWords;i++){
            string tem=s.substr(start+i*wordSize,wordSize);
            if(wordCount[tem]==0)
                return false;
            wordFound[tem]++;
            if(wordFound[tem]>wordCount[tem])
                return false;
        }
        return true;
    }
};//代码以我的这个为准，今天待会再写
