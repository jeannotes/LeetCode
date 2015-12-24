class Solution {
public:
    string addBinary(string a, string b) {
        if(a.length()<b.length())
            return addBinary(b,a);
        b.insert(b.begin(),a.length()-b.length(),'0');//此函数在p0处插入n个字符c
        int flag=0;
        for(int i=a.length()-1;i>=0;i--){
            int tem=int(a[i]-'0')+int(b[i]-'0')+flag;
            flag=tem/2;
            tem%=2;
            a[i]=char('0'+tem);
        }
        if(flag)
            a.insert(a.begin(),char('0'+flag));
        return a;
    }
};
