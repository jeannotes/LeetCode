class Solution {
public:
    string addBinary(string a, string b) {
        if(a.length()<b.length())
            return addBinary(b,a);
        b.insert(b.begin(),a.length()-b.length(),'0');
        int flag=0;
        for(int i=a.length()-1;i>=0;i--){
            int sum=(int)(a[i]-'0')+(int)(b[i]-'0')+flag;
            a[i]=char(sum%2+'0');
            flag=sum/2;
        }
        if(flag)
            a.insert(a.begin(),'1');
        return a;
    }
};
