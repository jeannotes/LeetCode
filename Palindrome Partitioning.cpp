class Solution {
public:
    vector<vector<string>>result;
	vector<string>tem;
	vector<vector<string>> partition(string s) {
		partitionHelper(s,0);
		return result;
	}

	void partitionHelper(string& s,int start){
		if (start==s.size()){
			result.push_back(tem);
			return;
		}
		for (int i=start;i<s.size();i++){
			
			if (isPalindrome(s,start,i)){
				string tmp=s.substr(start,i-start+1);
				tem.push_back(tmp);
				partitionHelper(s,i+1);
				tem.pop_back();
			}
		}
	}

	bool isPalindrome(string& s,int start,int end){
		int i=start,j=end;
		while (i<=j){
			if (s[i]!=s[j]){
				return false;
			}
			i++;j--;
		}
		return true;
	}
};
//，没想到用回溯啊。  其实有关值传递的问题，联系刚刚做的binary tree max pathsum的问题，
//那边的num不就相当于这儿的start吗,只不过在哪里 用了sum全局变量啊
// 都是些小毛病啊，但是改不掉
