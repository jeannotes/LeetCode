class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.length()<num2.length()){
            return multiply( num2, num1);
        }
        
        int m=num1.length(),n=num2.length();
        string res;
        for(int i=n-1;i>=0;i--){
            string tem=multiplySingleNumber( num1,num2[i]);
            string tem2(n-1-i,'0');
            tem+=tem2;
            res=addString(res,tem);
        }
        
        return res;
    }
    
    string multiplySingleNumber(string num,char c){
        if(c=='0')
            return "0";
        int flag=0;
        for(int i=num.length()-1;i>=0;i--){
            int tem= (num[i]-'0')*(c-'0')+flag;
            flag=tem/10;
            num[i]=(tem%10)+'0';
        }
        if(flag>0){
            num.insert(num.begin(),'0'+flag);
        }
        
        return num;
    }
    
        string addString(string num1,string num2){
        if(num1.length()<num2.length()){
            return addString( num2, num1);
        }
        
        int m=num1.length(),n=num2.length();
        int i=m-1,j=n-1;
        int flag=0;
        
        while(i>=0){
            int tem=num1[i]-'0'+flag;
            if(j>=0){
                tem+=num2[j]-'0';
                j--;
            }
            num1[i]=tem%10+'0';//加号表示字符
            i--;
            flag=tem/10;
        }
        if(flag>0)
            num1.insert(num1.begin(),'0'+flag);
        return num1;
    }
};
