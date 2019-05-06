class Solution {
public:
    bool isPalindrome_string(string res) {
        if(res.size() <=1) return true;
        int len = res.size();
        if(res[0]!=res[len-1]) return false;
        
        string inside = res.substr(1,len-2);
        
        return isPalindrome_string(inside);
    }
    
    bool isPalindrome(int x) {
        if(x < 0) return false;
        
        string res = to_string(x);
         
        return isPalindrome_string(res);
    }
};
// better solution
