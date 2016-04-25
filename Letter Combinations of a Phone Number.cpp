class Solution {
public:
    vector<string> res;
    string tmp;
    vector<string> letterCombinations(string digits) {
    	if (digits.empty()){
    		return res;
    	}
    	string table[]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    	letterHelper(0,digits,table);
    	return res;
    }
    
    void letterHelper(int start,string &digits,string table[]){
    	if (start==digits.size()){
    		res.push_back(tmp);
    		return;
    	}
    	int p=digits[start]-'2';
    	for (int i=0;i<table[p].size();i++){
    		tmp+=table[p][i];
    		letterHelper(start+1,digits,table);
    		tmp.pop_back();
    	}
    }
};
//代码更加简洁
// 在定义 字符串数组那边还有问题啊
