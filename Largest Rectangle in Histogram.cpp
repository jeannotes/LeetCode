class Solution {
public:
	int largestRectangleArea(vector<int> &height) {
		int len=height.size();
		int lBorder,rBorder=0;
		int res=0;
		//http://www.cnblogs.com/TenosDoIt/p/3454634.html
		//本题目的核心在于不是通过每一个循环判断最大值，而是
		//通过优化大数据，找到最右边边界，再去循环判断
		//一开始我想像其中一个题目一样，把每一点最左边最小值保存起来，似乎是想错了。
		//因为高度不确定，并不是连续变化的
		while (rBorder<len){
			if (rBorder+1<=len-1&&height[rBorder+1]>=height[rBorder]){
				rBorder++;
			}
			else{
				//说明找到最右边边界。
				//开始寻找最左边边界。
				//并且能够保证从头到这个边界，最大高度不会超过他
				int minVal=height[rBorder];
				for (lBorder=rBorder;lBorder>=0;lBorder--){
					if(minVal>height[lBorder])
						minVal=height[lBorder];
					int temp=(rBorder-lBorder+1)*minVal;
					res=max(res,temp);
				}
				
				//一开始开头写的是lBorder=rBorder-1,其实是没有考虑到自己也可以成为单独的一列。
				//
				rBorder++;
			}
		}
		return res;
	}
};
