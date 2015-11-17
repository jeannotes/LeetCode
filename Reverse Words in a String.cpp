class Solution {
public:
    void reverseWords(string &s) {
        if(s.empty())   return;
        int i=0,k=0;
        while(s[i]==' '&&i<s.length()){
            i++;
        }
        //i此时不为空
        while(i<s.length()){
            int start=k;
            while(s[i]!=' '&&i<s.length()){
                s[k++]=s[i++];
            }//此时i空
            if(k>start+1){
                reverseSubWord( s, start,k-1);
            }
            
            while(s[i]==' '&&i<s.length()){
                i++;
            }
            if(i<s.length())    s[k++]=' ';//一开始是这个地方没有设置，如果i到了最后，就不要设置空格
        }
        
        if(k<s.length()){
            s.erase(s.begin()+k,s.end());
        }
        
        if(k >1) reverseSubWord( s, 0,k-1) ;
    }
    
    void reverseSubWord(string &s,int start,int end){
        while(start<=end){
            swap(s[start],s[end]);
            start++;end--;
        }
    }
    
};
