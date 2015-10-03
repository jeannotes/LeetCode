class Solution {
public:
//https://leetcode.com/problems/generate-parentheses/
    void parensHelper(int left,int right,int n,vector<string>&result,string temp){
        if(right==n){
            //右边等于n说明满了，插入temp，返回
            result.push_back(temp);
            return;
        }
        
        if(left<n){
            //深度优先
            temp+='(';
            parensHelper(left+1,right,n,result,temp);
            temp.pop_back();
        }
        //到现在，尽管dfs题目做的很少，但是发现每每深度优先搜索之后，一定有“出栈”，方便下一个入口函数
        if(left>right){
            temp+=')';
            parensHelper(left,right+1,n,result,temp);
            temp.pop_back();
        }
    }       //      ( ( ( ) ) ) -- ( ( ( ) ) ) -- 

    vector<string> generateParenthesis(int n) 
    {
        string temp;
        vector<string> result;
        parensHelper(0,0,n,result,temp);
        return result;
    }


    
};
