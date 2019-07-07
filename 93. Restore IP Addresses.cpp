class Solution {
public:
    vector<string> res;
    string temp;
    vector<string> restoreIpAddresses(string s) {
        if (s.empty() || s.size() > 12)
		    return res;
        restoreHelper(s, 1, 0);
        return res;
    }
    
    void restoreHelper(string s, int index, int start){
        if(index == 4){
            string ip = s.substr(start);
            if(isValid(ip)){
                temp+=ip;
                res.push_back(temp);
            }
        }
        
        for(int i=1;i<4 && s.size()-i-start >=4-index ;i++){
            string ip = s.substr(start, i);
            if(isValid(ip)){
                int len = temp.size();
                temp+=ip;
                temp+='.';
                restoreHelper(s, index+1, start+i);
                temp.resize(len);
            }
        }
    }
    
    bool isValid(string s){
        if(s.empty()) return false;
        if(s.size()>1 && s[0]=='0') return false;
        int num = stoi(s);
        return 0<=num && num<=255;
    }
};
//总算是能够理解一丢丢
// 想了好久，仅仅知道i=1,2,3,第二天早上做的，有些会了
// 还是不会啊，开头的条件还是不会啊，加油，还行，以后每天就写一小段
