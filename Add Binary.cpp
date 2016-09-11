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




//最好的程序  待会儿看一下可以啊
class Solution {
public:
    string addBinary(string a, string b) {
    	string s;
    	int i=a.length()-1,j=b.length()-1,c=0;
    	while (i>=0||j>=0||c>0){
    		c+=i>=0?(int)(a[i--]-'0'):0;
    		c+=j>=0?(int)(b[j--]-'0'):0;
    		s=char(c%2+'0')+s;
    		c=c/2;
    	}
    	return s;
    }
};
