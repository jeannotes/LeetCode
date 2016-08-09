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

vector<int>res;
vector<int> findSubstring(string s, vector<string>& words) {
	if (s.empty() || words.empty())
		return res;
	int wordCount = words.size(),
		wordSize = words[0].size(),
		totalSize = wordCount*wordSize;
	if (s.size() < totalSize)
		return res;
	unordered_map<string, int>wordExist;
	for (int i = 0; i < wordCount; i++) {
		wordExist[words[i]]++;
	}

	for (int i = 0; i <=s.size()-totalSize;i++) {
		if (check(s, words, i, wordExist, wordCount, wordSize))
			res.push_back(i);
	}
	return res;
}

bool check(string s, vector<string>& words, int start, unordered_map<string, int>wordExist,
	int wordCount,int wordSize) {
	if (s.size() - start < wordCount*wordSize)
		return false;
	unordered_map<string, int>wordFound;
	for (int i = 0; i < wordCount;i++) {
		string tem = s.substr(start + i*wordSize, wordSize);
		if (wordExist[tem] == 0)
			return false;
		wordFound[tem]++;
		if (wordFound[tem]>wordExist[tem])
			return false;
	}
	return true;
}
// 还可以，不会啊
