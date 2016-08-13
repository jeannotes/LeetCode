//https://leetcode.com/discuss/12790/my-code-in-java  非常好的帖子
class Solution {
public:
    string tem; vector<string>res;
    void restoreHelper(string &s, int pos, int index) {
    	if (pos == 4) {
    		string ip = s.substr(index);
    		if (isValid(ip)) {
    			tem += ip; res.push_back(tem);
    		} 
    		return;
    	}
    	for (int i = 1;i<4&&(s.size()-index-i>=4-pos);i++) {
    		string ip=s.substr(index,i);
			if (isValid(ip)) {
				int size = tem.size();
					tem += ip; tem += '.';
					restoreHelper(s,pos+1,index+i);
					tem.resize(size);
			}
    	}
    }
    
    bool isValid(string s) {
    	if (s.size() > 1 && s[0] == '0')
    		return false;
    	int num = stoi(s);
    	return (num >= 0 && num <= 255);
    }
    
    vector<string> restoreIpAddresses(string s) {
    	if (s.size() < 4 || s.size() > 12)
    		return res;
    	restoreHelper(s, 1, 0);
    	return res;
    }

};
//总算是能够理解一丢丢
// 想了好久，仅仅知道i=1,2,3,第二天早上做的，有些会了
// 还是不会啊，开头的条件还是不会啊，加油，还行，以后每天就写一小段
