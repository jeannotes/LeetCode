class Solution {
public:
    string convert(string s, int numRows) {
        if(s.size()<=2) return s;
        if(numRows == 1) return s; 
        vector<string> strings(numRows);
        for(int i=0;i<s.size();i++){
            int len = i%(2*numRows-2);
            if(len<= numRows-1){
                strings[len]+=s[i]; 
            }else{
                int temp =(2*numRows-2)-len;
                strings[temp]+=s[i]; 
            }
        }
        string res;
        for(auto s : strings){
            res=res+s;
        }
        
        return res;
    }
};
