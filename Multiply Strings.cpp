class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.length()<num2.length()){
            return multiply( num2, num1);
        }
        vector<string>res;
        int len1=num1.length(),len2=num2.length();
        
        for(int i=len2-1;i>=0;i--){
            string tem=string_multiply(num1,num2[i]);
            tem.append(len2-i-1,'0');
            res.push_back(tem);
        }
        for(int i=1;i<res.size();i++){
            res[0]=string_add(res[0],res[i]);
        }
        return res[0];
    }
    
    string string_multiply(string num,char c){
        if(c=='0')
            return "0";
        int flag=0;
        string res;
        for(int i=num.length()-1;i>=0;i--){
            int tem=int(num[i]-'0') * int(c-'0')+flag;
            res+=char(tem%10+'0');
            flag=tem/10;
        }
        if(flag)
            res+=char(flag+'0');
        reverse(res.begin(),res.end());
        return res;
    }
    
    string string_add(string num1,string num2){
        if(num1.length()<num2.length())
            return string_add(num2,num1);
        int len1=num1.length(),len2=num2.length();
        int i=len1-1,j=len2-1,flag=0;
        string res;
        while(i>=0&&j>=0){
            int tem=(int)(num1[i]-'0')+(int)(num2[j]-'0')+flag;
            num1[i]=char(tem%10+'0');
            flag=tem/10;i--;j--;
        }
        while(i>=0){
            int tem=(int)(num1[i]-'0')+flag;
            num1[i]=char(tem%10+'0');
            flag=tem/10;i--;
        }
        if(flag)
            num1.insert(num1.begin(),char(flag+'0'));
        return num1;
    }
};
//bug-exist  都是小错误，但是继续加油！
