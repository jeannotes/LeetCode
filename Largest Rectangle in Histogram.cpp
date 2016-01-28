class Solution {
public:
//http://www.cnblogs.com/lichen782/p/leetcode_Largest_Rectangle_in_Histogram.html
    int largestRectangleArea(vector<int>& height) {
        stack<int>s;
        int sum=0;
        height.push_back(0);//就是为了最后循环能够结束
         
        for(int i=0;i<height.size();i++){
            if(s.empty()||height[i]>height[s.top()])
                s.push(i);
            else{
                int tmp=s.top();
                s.pop();
                sum=max(sum,height[tmp]*(s.empty()?i:i-1-s.top()));
                i--;//当前的判断了，需要减1，待会有i++，才能对当前i值继续判断
            }
        }
        return sum;
    }
};
