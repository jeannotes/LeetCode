class Solution {
public:
    string getPermutation(int n, int k) {
        string ret;
        vector<int> factorial(n,1);
        vector<char> num(n,1);
        
        for(int i=1; i<n; i++) 
            factorial[i] = factorial[i-1]*i;
        
        for(int i=0; i<n; i++)
            num[i] = (i+1)+'0';
        
        k--;
        for(int i=n; i>=1; i--) {
            int j = k/factorial[i-1];
            k %= factorial[i-1];
            ret.push_back(num[j]);
            num.erase(num.begin()+j);
        }
        
        return ret;
    }
};
//http://bangbingsyb.blogspot.com/2014/11/leetcode-permutation-sequence.html
//不会啊
//add binary 中是强制转换为数字的时候用减号  强制字符的时候用加号，感觉还不错啊
//不会了啊，然而我还是不会啊，第二天做，还是各种小错误，还行，要按照例子来
