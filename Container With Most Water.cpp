class Solution {
public:
    int maxArea(vector<int>& height) {
        int res=0;
        int i=0,j=height.size()-1;
        while(i< j){
            int temp=(j-i)*min(height[i],height[j]);
            if(temp>res){
                res=temp;
            }
            if(height[i]>height[j]){
                j--;
            } else if(height[i]<height[j]){
                i++;
            }else{
               i++;j--;
            }
        }
        
        return res;
    }
};

//我在最两边找到位置，接下来就是往中间走，如果左边的往右走的时候比刚才最小的还小，继续往右走，对于右边，同样的道理
 //本题的意思不在于像之前的trapping rain water 一样，需要考虑位置，体积啥的，
        //他只是单纯的问我们两根线连起来和x轴有没有最大值。
// 不太会做啊
//  左边的大，右边的往左走，左边的小，左边的往右走
//还是不会啊
