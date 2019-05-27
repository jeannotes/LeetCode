class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        int len = s.size();
        std::set<char> set;
        int i=0,j=0;
        int res = 0;
        while(i<len &&j<len){
            if(set.count(s[j]) ==0 ){
                set.insert(s[j++]);
                res = std::max(res, j-i);
            }else{
                set.erase(s[i++]);
            }
        }
        
        return res;
    }
};
/*
这个方法其实非常好，解释是这样的，只要没有遇到相同的字符，那么不断的增加字符到set
如果有，那么把最一开始的删除掉，这里其实已经说明了，过去的一段字符串也已经考虑到了。所以不用担心，
我们真正关心的就是（abba）里面（bba），从第一个b开始，是不是有最大的。而代码里面把最一开始的给删除掉就是为了这个。
*/
