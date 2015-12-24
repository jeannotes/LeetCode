class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.empty())
            return digits;
        int flag=0;
        
        flag=(digits[digits.size()-1]+1)/10;
        digits[digits.size()-1]=(digits[digits.size()-1]+1)%10;
        
        for(int i=digits.size()-2;i>=0;i--){
            int tem=digits[i]+flag;//注意体会为什么设立 tem变量，如果没有，那么会导致后面的两个语句tem值不一样。
            flag=(tem)/10;
            digits[i]=(tem)%10;
        }
        if(flag)
            digits.insert(digits.begin() ,flag);
        return digits;
        
    }
};
