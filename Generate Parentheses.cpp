class Solution {
public:
//https://leetcode.com/problems/generate-parentheses/
    void parensHelper(int left,int right,int n,vector<string>&result,string temp){
        if(right==n){
            //右边等于n说明满了，插入temp，返回
            result.push_back(temp);
            return;
        }
        /*
        if(left>=n)
            return;*/  //这里不能加上这一句话，一旦加上，假使left>n，return之后就不会在之后添加）了
        if(left<n){//这里不能给写成left<right，因为一开始right=0
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

    vector<string> generateParenthesis(int n){
        string temp;
        vector<string> result;
        parensHelper(0,0,n,result,temp);
        return result;
    }

};
// 还是不会啊
// 还是不会啊
