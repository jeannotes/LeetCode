class Solution {
public:
//https://leetcode.com/problems/multiply-strings/
        string addBig(string num1,string num2){
            int m=num1.size(),n=num2.size();
            
            if(m<n){
                swap(num1,num2);
                swap(m,n);
            }
            
            int flag=0,i=m-1,j=n-1;
            int a=0;
            while(i>=0){
                if(i>=0){
                    a+=num1[i]-'0'+flag;
                }
                if(j>=0){
                    a+=num2[j--]-'0';
                }
                flag=a/10;
                num1[i--]=(a)%10+'0';a=0;
            }
            if(flag>0){
                num1.insert(num1.begin(),flag+'0');
            }   
            /*
            int a = 0, i=m-1, j=n-1;
            while (i >= 0) {
            int x = a;
            if (i >= 0)
                x += num1[i--] - '0';
            if (j >= 0)
                x += num2[j--] - '0';
                
            num1[i+1] = x % 10 + '0';
            a = x / 10;
        }
        
        if (a > 0) 
            num1.insert(num1.begin(), '1');
            */
            return num1;
        }

        string multiplySingleNumber(string num,char c){
            string result;
            int flag=0;
            if(c=='0')  {
                return "0";
            }
            for(int i=num.length()-1;i>=0;i--){
                int a=(num[i]-'0')*(c-'0')+flag;
                num[i]=(a)%10+'0';
                flag=a/10;
            }
            if(flag>0){
                num.insert(num.begin(),flag+'0');
            }
            return num;
        }


    string multiply(string num1, string num2) {
        
        int m=num1.size();
        int n=num2.size();
        
        if(m<n){
            swap(m,n);
            swap(num1,num2);
        }
        string result,zeros;
        result="0";
        for(int i=n-1;i>=0;i--){
            if(num2[i]!='0'){
            string s=multiplySingleNumber(num1,num2[i]);
            s+=zeros;
            result=addBig(s,result);
            }
            zeros.append(1,'0');
        }
        
        /*for(int i=n-1;i>=0;i--){
            if(num2[i]!='0'){
            zeros=multiplySingleNumber(num1,num2[i]);
            zeros.append(n-1-i,'0');
            result=addBig(zeros,result);
            }
        }*/
        while((int)result.size()>1&&result[0]=='0'){
            result.erase(result.begin());
        }
        return result;
        
    }
    
};
