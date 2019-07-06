class Solution {
public:
string res1;
vector<string> res;
vector<string> restoreIpAddresses(string s) {
	if (s.empty() || s.size() > 12)
		return res;
	restoreIpAddressesHelper(s, 1, 0);
	return res;
}

void restoreIpAddressesHelper(string s,int index,int start) {
	if (index == 4) {
		string ip = s.substr(start);
		if (isValid(ip)) {
			res1 += ip;
			res.push_back(res1);
			return;
		}
	}
	for (int i = 1; i <= 3 && (s.size()-start-i>=4-index);i++) {
		string ip = s.substr(start, i);
		if (isValid(ip)) {
			int len = res1.size();
			res1 += ip; res1 += '.';
			restoreIpAddressesHelper(s, index + 1, start + i);
			res1.resize(len);
		}
	}
}

bool isValid(string s) {
    if (s.size() > 1 && s[0] == '0')
		return false;
	int tem = stoi(s);
	return 0 <= tem&&tem <= 255;
}
};
//总算是能够理解一丢丢
// 想了好久，仅仅知道i=1,2,3,第二天早上做的，有些会了
// 还是不会啊，开头的条件还是不会啊，加油，还行，以后每天就写一小段
