class Solution {
public:
    int trap(vector<int>& height) {
		int n=height.size();//数组长度

		if (n==0||n==1)
		{
			return 0;
		}
		else
		{
			int i=0;
			vector<int> LeftMostHeight(n);//定义左右两端距离自己最高的数组
			vector<int> RightMostHeight(n);

			int lheight=0;
			//计算左边的距离每一点的最大高度
			for ( i = 0; i < n; i++)
			{
				LeftMostHeight[i]=lheight;
				lheight=height[i]>lheight?height[i]:lheight;
			}
			lheight=0;
			//计算右边的距离每一点的最大高度
			for ( i = n-1; i >=0; i--)
			{
				RightMostHeight[i]=lheight;
				lheight=lheight>height[i]?lheight:height[i];
			}
			//至此数组计算完毕

			//接下来开始计算
			int res=0;
			for (int i = 0; i < n; i++)
			{
			    //min(LeftMostHeight[i],RightMostHeight[i])-height[i]
				res+=(min(LeftMostHeight[i],RightMostHeight[i])-height[i])>0?(min(LeftMostHeight[i],RightMostHeight[i])-height[i]):0;
			}
			return res;
		}
		
    }
};
