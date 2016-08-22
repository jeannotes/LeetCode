class Solution {
    //http://www.cnblogs.com/TenosDoIt/p/3461301.html
    //https://leetcode.com/discuss/72701/here-10-line-template-that-can-solve-most-substring-problems
public:
    string minWindow(string s, string t) {
        string result;
        if(s.empty()||t.empty())
            return result;
        unordered_map<char,int>number_in_t;
        unordered_map<char,int>number_found_in_t;
        int hasFound=0,minLength=INT_MAX;
        
        for(int i=0;i<t.length();i++)
            number_in_t[t[i]]++;
        
        for(int i=0,start=0;i<s.length();i++){//这里不能写成 i<=s.length()-t.length()，因为start是在变化的，不是纯粹的滑块法
            char c=s[i];
            if(number_in_t.find(c)!=number_in_t.end()){
                number_found_in_t[c]++;
                if(number_found_in_t[c]<=number_in_t[c])
                    hasFound++;
                
                if(hasFound==t.length()){
                    //重新确定范围
                    while(number_in_t.find(s[start])==number_in_t.end()
                            ||number_in_t[s[start]]<number_found_in_t[s[start]]){
                        
                        number_found_in_t[s[start]]--;
                        start++;
                    }
                    
                    if(i-start+1<minLength){
                        minLength=i-start+1;
                        result=s.substr(start,minLength);
                    }
                }
            }
        }
        return result;
    }
};
//就是不会啊
//记住，中间 -- if(hasFound==t.length()) 这一句话是不能放在上面一个if从句里面的，因为hasFound并没有变化，
//如果放在那个里面，每次都不会变化的 "bdab"-"ab",最后仅仅输出-"bda"，因为每次hasFound都是3
//意思是会，竟然一次AC啊
//  这次不是什么大问题，但是不等于号没有写啊，还是不行，各种错误啊
//  第一不是简单的滑块法，需要，i一直要到最后的，有可能到最后是最大值。第二，diff初始化不能是s.size(),假如
//出现 s="a",t="a" 这种情况，就会出问题了
