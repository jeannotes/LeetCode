class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty())
            return 0;
        int len=height.size();
        int leftHeight[len],rightHeight[len];
        int leftTemp=0,rightTemp=0;
        int res=0;
        
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
