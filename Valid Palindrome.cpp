class Solution1 {
public:
    bool isPalindrome(string s) {
        string r = "";
        for (int i = 0; i < s.size(); ++i) {
            if (checkAlpha(s[i])) r += lowerLetter(s[i]);
        }
        int l = r.size();
        for (int i = 0; i < l / 2; ++i)
            if (r[i] != r[l - i - 1]) return false;
        return true;
    }
    
    bool checkAlpha(char c){
		if( (c<='z'&&c>='a') || (c<='Z'&&c>='A')||(c >= '0' && c <= '9') ){
			return true;
		}
		return false;
	}
	 char lowerLetter(char& c){
		 if(c<='Z'&&c>='A'){
			 c=c-'A'+'a';
		 }
		 return c;
	 }
};

class Solution2 {
public:
    bool isPalindrome(string s) {
        string r = "";
        for (int i = 0; i < s.size(); ++i) {
            if (isalnum(s[i])) r += tolower(s[i]);
        }
        int l = r.size();
        for (int i = 0; i < l / 2; ++i)
            if (r[i] != r[l - i - 1]) return false;
        return true;
    }
};
//第二个方法使用了库函数,竟然没有一次通过,基本没问题啊
//  惭愧啊，或 与那边还是出问题啊
