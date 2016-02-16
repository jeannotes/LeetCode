class Solution {
private:
    void restoreHelper(string &s, int start, vector<string> &addr, vector<string> &result) {
        if (addr.size() == 4) {
            if (start == s.size()) {
                string ipstr(addr[0]);
                for (int i = 1; i < 4; i++) {
                    ipstr.push_back('.');
                    ipstr.append(addr[i]);
                }
                result.push_back(ipstr);
            }
            return ;
        }
        if (start == s.size()) return;
        
        for (int v = 0,i = 0 ; i < 3 && start + i < s.size(); i++) {
            v = v * 10 + s[start+i] - '0';
            //这个地方很巧妙，i=0，代表支取1位，但是第一次保存了v的值，等到第二次循环，v
            //已经计算了下一位的值。
            if (v < 256) {
                addr.push_back(s.substr(start,i+1));//i=0的时候放进去1个数字
                restoreHelper( s, start+i+1, addr, result);//接下来从start+i+1开始，因为
                                                           //刚刚从start开始，一共i+1个数字
                addr.pop_back();
            }
            if(v==0||v>255) break;//因为这个时候v不满足要求，那么他代表的是当前的这个循环
                                  //直接退出，返回上一层递归调用的函数
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> addr;
        restoreHelper(s, 0, addr, result);
        return result;
    }
};
// 不会，好题目
