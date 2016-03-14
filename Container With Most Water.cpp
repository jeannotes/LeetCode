class Solution {
public:
    int maxArea(vector<int>& height) {
    	int water=0;
    	int i=0,j=height.size()-1;
    	while (i<j){
    		int h=min(height[i],height[j]);
    		water=max(water,h*(j-i));
    		while (height[i]<=h&& i < j){
    			i++;
    		}
    		while (height[j]<=h&& i < j){
    			j--;
    		}
    	}
    	return water;
    }
};

//我在最两边找到位置，接下来就是往中间走，如果左边的往右走的时候比刚才最小的还小，继续往右走，对于右边，同样的道理
 //本题的意思不在于像之前的trapping rain water 一样，需要考虑位置，体积啥的，
        //他只是单纯的问我们两根线连起来和x轴有没有最大值。
// 不太会做啊
