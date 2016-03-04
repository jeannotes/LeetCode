class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.empty())
            return digits;
        int flag=0 , len=digits.size()-1 ;
        for(int i=len;i>=0;i--){
            int tem=(i==len?1:0)+flag+digits[i];
            flag=tem/10;
            digits[i]=tem%10;
        }
        if(flag)
            digits.insert(digits.begin(),flag);
        return digits;
    }
};
// 不够简洁，中间分开了，另外最后return 没有写
//digits.insert 这个函数忘记了
