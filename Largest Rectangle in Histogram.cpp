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
//这个题目很难，以后再做！！！
//还是不会，尤其是这个i++ 那个地方要理解
//  (s.empty()?i:i-1-s.top())  这个地方为什么有可能出现empty呢，这是因为出现6 5 4 3 2 1的时候，每次都是空。对应这种情况就是这样的写法
//通过
//不会   对于 [4,2,0,3,2,5]  如果用 i-tem会导致之前大的一个数字所在的面积没有计算进去
