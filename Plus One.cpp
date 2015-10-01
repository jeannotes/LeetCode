class Solution {
public:
//https://leetcode.com/problems/plus-one/
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int flag=0;
        
        if(digits[digits.size()-1]+1+flag>=10){
                
                result.push_back((digits[digits.size()-1]+1+flag)%10);flag=1;
            }else{
                result.push_back(digits[digits.size()-1]+1+flag);
                flag=0;
            }
        
        for(int i=digits.size()-2;i>=0;i--){
            if(digits[i]+flag>=10){
                
                result.push_back((digits[i]+flag)%10);flag=1;
            }else{
                result.push_back(digits[i]+flag);
                flag=0;
            }
        }
        if(flag){
            result.push_back(flag);
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
