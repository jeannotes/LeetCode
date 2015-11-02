class Solution {
public:
    int maxArea(vector<int>& height) {
        //本题的意思不在于像之前的trapping rain water 一样，需要考虑位置，体积啥的，
        //他只是单纯的问我们两根线连起来和x轴有没有最大值。
        int res=0;
        int i=0,j=height.size()-1;
        while(i<=j){
            int temp=(j-i)*min(height[i],height[j]);
            if(temp>res){
                res=temp;
            }
            if(height[i]>height[j]){
                j--;
            }
            else if(height[i]<height[j]){
                i++;
            }
            else{
                i++;j--;
            }
        }

        return res;
    }
};
