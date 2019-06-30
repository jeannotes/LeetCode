class Solution {
//https://leetcode.com/problems/length-of-last-word/
public:
    int lengthOfLastWord(string s) {
    	if (s.empty())
    		return 0;
    	int j=s.size()-1,count=0;
    	while (s[j]==' '&&j>=0){
    		j--;
    	}
    	while (s[j]!=' '&&j>=0){
    		count++;j--;
    	}
    	return count;
    }
};
// bug-free
//基本没问题
//竟然有问题啊
