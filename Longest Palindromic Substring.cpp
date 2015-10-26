class Solution1 {
public:
//在之前有一个题目使用自下而上的解法
//http://articles.leetcode.com/2011/11/longest-palindromic-substring-part-i.html
//这只是第一种想法，还有一种待会写。

    string expandAroundCenter(string s, int c1, int c2) {
  int l = c1, r = c2;
  int n = s.length();
  while (l >= 0 && r <= n-1 && s[l] == s[r]) {
    l--;
    r++;
  }
  return s.substr(l+1, r-l-1);
}
 
string longestPalindrome(string s) {
  int n = s.length();
  if (n == 0) return "";
  string longest = s.substr(0, 1);  // a single char itself is a palindrome
  for (int i = 0; i < n-1; i++) {
    string p1 = expandAroundCenter(s, i, i);
    if (p1.length() > longest.length())
      longest = p1;
 
    string p2 = expandAroundCenter(s, i, i+1);
    if (p2.length() > longest.length())
      longest = p2;
  }
  return longest;
}

};

class Solution2 {
public:
//第二种写法，从中心拓展
    string longestPalindrome(string s){
        int n=s.length();
        if(n==0){
            return "";
        }
        string longest=s.substr(0,1);
        
        for(int i=0;i<n;i++){
            string p1=expandAroundCenter( s,i,i);//围绕中心i使劲往两边走
            if(p1.length()>=longest.length()){
                longest=p1;
            }
            string p2=expandAroundCenter( s,i,i+1);//围绕中心i使劲往两边走
            if(p2.length()>=longest.length()){
                longest=p2;
            }
        }
        return longest;
    } 
    string expandAroundCenter(string &s,int c1,int c2){
        int len=s.length();
        while(c1>=0&&c2<=len-1&&s[c1]==s[c2]){
            c1--;c2++;
        }
        return s.substr(c1+1,c2-c1-1);//第一个参数是起始位置，第二个是长度，闭区间
    }
};
