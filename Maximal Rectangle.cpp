class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()||matrix[0].empty())
            return 0;
        int m=matrix.size(),n=matrix[0].size();
        int area=0;
        vector<int>height(n,0);//初始化
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='0')
                    height[j]=0;
                else
                    height[j]++;
            }
            int tmp=largestRectangleArea(height);
            area=max(area,tmp);
        }
        return area;
    }
    
    int largestRectangleArea(vector<int>& height) {
        stack<int>s;
        int sum=0;
        height.push_back(0);
         
        for(int i=0;i<height.size();i++){
            if(s.empty()||height[i]>height[s.top()])
                s.push(i);
            else{
                int tmp=s.top();
                s.pop();
                sum=max(sum,height[tmp]*(s.empty()?i:i-1-s.top()));
                i--;
            }
        }
        return sum;
    }
};
