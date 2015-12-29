class Solution {
public:
//http://www.cnblogs.com/felixfang/p/3676193.html
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
