class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty())
            return 0;
        int len=height.size();
        int leftHeight[len],rightHeight[len];
        int leftTemp=0,rightTemp=0,res=0;
        
        //从左往右扫描，距离每一点最大点
        for(int i=0;i<len;i++){
            leftHeight[i]=leftTemp;
            leftTemp=max(height[i],leftTemp);
        }
        
        //从右往左扫描，距离每一点最大点
        for(int i=len-1;i>=0;i--){
            rightHeight[i]=rightTemp;
            rightTemp=max(height[i],rightTemp);
        }
        
        for(int i=0;i<len;i++){
            int tem=(min(leftHeight[i],rightHeight[i])-height[i])>0?(min(leftHeight[i],rightHeight[i])-height[i]):0;
            res+=tem;
        }
        
        return res;
    }
};
//基本一致通过，bug-free还是有问题的
//  写成简便的形式会出错
int trap(vector<int>& height) {
	if (height.empty())
		return 0;
	int len=height.size();
	vector<int> left(len,height[0]);
	vector<int> rigth(len,height[len-1]);
	int maxHeight=height[0];

	for (int i=1;i<len;i++){
		maxHeight=max(maxHeight,height[i]);
		left[i]=maxHeight;
	}
	maxHeight=height[len-1];
	for (int i=len-2;i>=0;i--){
		maxHeight=max(maxHeight,height[i]);
		rigth[i]=maxHeight;
	}
	int res=0;
	for (int i=0;i<len;i++){
		res+=(min(left[i],rigth[i])-height[i]);
	}
	return res;
}
