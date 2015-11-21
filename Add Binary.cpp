class Solution {
public:
    string addBinary(string a, string b) {
        int lenA=a.length(),lenB=b.length();
        
        if(lenA<lenB){
            return addBinary(b,a);
        }
        int pa=lenA-1,pb=lenB-1;
        int flag=0;
        string res="";
        string tem="";
        while(pb>=0){
            int sum=(int)(a[pa]-'0')+(int)(b[pb]-'0')+flag;
            tem+=(sum%2==1)?'1':'0';// sum总和 的三种情况 0,1,2。只有当和为1，返回1，其余都为0
            flag=sum/2;
            pa--;
            pb--;
        }
        while(pa>=0){
            int sum=(int)(a[pa]-'0')+flag;
            tem+=(sum%2==1)?'1':'0';// sum总和 的三种情况 0,1,2。只有当和为1，返回1，其余都为0
            flag=sum/2;
            pa--;
        }
        
        if(flag){
            tem=tem+'1';
        }
        reverse(tem.begin(),tem.end());
        return tem;
    }
};
