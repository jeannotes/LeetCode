class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        if(height.size()<=1) return 0;
        int left =0, right = height.size()-1;
        while(left <= right){
            int temp_res = min(height[left], height[right]) * (right - left);
            res = std::max(res, temp_res);
            
            if(height[left]<height[right])
                left++;
            else if(height[left]>height[right])
                right--;
            else{
                left++;
                right--;
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
/*
思路：

由于ai和aj (i<j) 组成的container的面积：S(i,j) = min(ai, aj) * (j-i)

所以对于任何S(i'>=i, j'<=j) >= S(i,j)，由于j'-i' <= j-i，必然要有min(ai',aj')>=min(ai,aj)才行。同样可以采用头尾双指针向中间移动：

当a(left) < a(right)时，对任何j<right来说

(1) min(a(left),aj) <= a(left) = min(a(left), a(right))
(2) j-left < right-left

所以S(left, right) > S(left, j<right)。排除了所有以left为左边界的组合，因此需要右移left。同理，当a(left) > a(right)时，需要左移right。而当a(left) = a(right)时，需要同时移动left和right。

思路整理：
left = 0, right = n-1
(1) a[left] < a[right], left++
(2) a[left] > a[right], right--
(3) a[left] = a[right], left++, right--
终止条件：left>-right

20241005 两边往中间走，万一中间的某一个区间没有遇到怎么办？  答案：不可能，因为一定是左边++，右边--，所以一定遇到

*/
// wait for LX to edit
