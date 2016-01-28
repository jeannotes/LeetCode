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
        if(num1.length()<num2.length())
            return addString(num2,num1);
        int len1=num1.length(),len2=num2.length();
        //len1>len2
        len1--;len2--;
        int flag=0;
        while(len1>=0&&len2>=0){
            int tem=int(num1[len1]-'0')+int(num2[len2]-'0')+flag;
            flag=tem/10;tem=tem%10;
            num1[len1]=char('0'+tem%10);
            len1--;len2--;
        }
        while(len1>=0){
            int tem=int(num1[len1]-'0')+flag;
            flag=tem/10;
            num1[len1]=char('0'+tem%10);
            len1--;
        }
        if(flag!=0)
            num1.insert(num1.begin(),char('0'+flag));
        return num1;
    }
};
