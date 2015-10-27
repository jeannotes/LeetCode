class Solution {
public:
    string convert(string s, int numRows) {
        int len=s.length();
        if(numRows==1||len<=numRows){//还没有numRows大，直接从上往下读
            return s;
        }
        string result;
        int gap=2*numRows-2;
        for(int i=0;i<numRows;i++){
            for(int j=i;j<len;j=j+gap){
                result.push_back(s[j]);
                if(i>0&&i<numRows-1&&(j+gap-2*i)<len){
                    result.push_back(s[j+gap-2*i]);
                }
                //除去第一行和最后一行，第二列之字形的数字
            }
        }
        
        return result;
    }
};
