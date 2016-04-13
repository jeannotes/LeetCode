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
        height.pop_back();
        return sum;
    }
};
//有问题啊，函数里面是引用，每次应该都会加上一个数字的，只是这不会出现问题，每次都加0，这不影响后期的解算，就算后面无数个0.
//所以这次，我加了一句 --  height.pop_back();
//  注意开始vector 那边 n个数字就行 因为程序里面是要push_back的  还有，类型是char
