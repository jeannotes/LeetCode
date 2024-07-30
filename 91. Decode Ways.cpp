class Solution {
public:
    int numDecodings(string s) {
        s = '0'+s;
        int len = s.size();
        vector<int> sum(len, 0);
        sum[0]=1; 
        for(int i=1; i<len; i++){
            if(s[i]=='0') sum[i]=0;
            else sum[i]=sum[i-1]; 
            if(i>=2){
                int tem = (s[i-1]-'0')*10 + (s[i]-'0');
                if(10 <= tem && tem <= 26)
                    sum[i]+=sum[i-2]; 
            }
        }
        return sum[len-1];
    }
};
