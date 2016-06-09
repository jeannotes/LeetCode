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
//加油,还是不会啊,有瑕疵，start+i这一块没有注意到
//有瑕疵，start+i这一块没有注意到,竟然犯同样的错误
//还是不会啊
