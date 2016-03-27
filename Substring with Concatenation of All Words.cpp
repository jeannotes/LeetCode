class Solution {
//https://leetcode.com/problems/substring-with-concatenation-of-all-words/
//本题主要还是使用滑块法，就是从左往右依次滑动，然后检查这个位置是否存在
public:
       vector<int> findSubstring(string s, vector<string>& words) {
    	vector<int>res;
    	if (s.empty()){
    		return res;
    	}
    	int totalWords=words.size();
    	int wordSize=words[0].size();
    	int totalLen=totalWords*wordSize;
    
    	if (s.size()<totalLen){
    		return res;
    	}
    
    	unordered_map<string,int>wordCount;
    	for (int i=0;i<totalWords;i++){
    		wordCount[words[i]]++;
    	}
    
    	for (int i=0;i<=s.length()-totalLen;i++){
    		if (checkSubstring(s,i,wordCount,wordSize,totalWords)){
    			res.push_back(i);
    		}
    	}
    	return res;
    }
    
    bool checkSubstring(string& s,int start,unordered_map<string,int>& wordCount,int wordSize
    	,int totalWords){
    	if (s.size()-start+1<wordSize*totalWords){
    		return false;
    	}
    	unordered_map<string,int>wordFound;
    	for (int i=0;i<totalWords;i++){
    		string tmp=s.substr(start+i*wordSize,wordSize);
    		if (!wordCount.count(tmp)){
    			return false;
    		}
    		wordFound[tmp]++;
    		if (wordFound[tmp]>wordCount[tmp]){
    			return false;
    		}
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
        vector<int>res;
        if(s.length()<totalLen)
            return res;
        if(words.empty())
            return res;
        unordered_map<string,int>wordCount;
        for(int i=0;i<totalWords;i++){
            wordCount[words[i]]++;
        }
        int len1=s.length(),len2=totalLen;
        for(int i=0;i<=len1-len2;i++){
            if(check(i,s,words,wordSize,totalWords,totalLen,wordCount))
                res.push_back(i);
        }
        return res;
    }
    
    bool check(int start,string& s,vector<string>& words,int wordSize,int totalWords,int totalLen
                ,unordered_map<string,int>wordCount){
            if(s.length()-start<totalLen)
                return false;
            unordered_map<string,int>wordFound;
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
};
// 一次通过
// 不是一次通过，略有抄袭
