class Solution {
//https://leetcode.com/problems/longest-substring-without-repeating-characters/
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>m;
        int last=-1;
        int maxLen=0;
        for(int i=0;i<s.size();i++){
            if(m.find(s[i])!=m.end()&&last<m[s[i]]){
                last=m[s[i]];
            }
            maxLen=max(maxLen,i-last);
            m[s[i]]=i;
        }
        return maxLen;
    }
    //直观的一个理解就是从头往后，定义一个hash表，存入字符以及具体索引值，当发现找到已经存在的字符的时候，但注意，一定要是上一个重复的
    //点的索引值在这个重复点之前  比如 a b b a
    //在没有遇到重复点之前，所有的按计划操作，，等到出现重复字符的时候，
    //把上一次的索引值保存在last里面，这个时候的i - lastRepeatPos一般不会大于maxLen 的，除非start就在隔壁。
    //而且这个有一个好处就是，在没有出现重复字符之前，它能够自动更新。
    //当然这里面涉及一个+1和-1的问题，虽然保存last=m[s[i]];但是实际上需要一个+1再-1的计算
};
//1 python的版本慢慢来的
class Solution(object):
    def lengthOfLongestSubstring(self,s):
        longest,start,visited=0,0,[False for _ in xrange(256)]

        for i,char in enumerate(s):
            if visited[ord(char)]:
                while char != s[start]:
                    visited[ord(s[start])]=False
                    start+=1
                start+=1
            else:
                visited[ord(char)]=True
            longest=max(longest,i-start+1)
        return longest
