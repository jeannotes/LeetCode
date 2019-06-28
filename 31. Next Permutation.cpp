class Solution {
public:
    // http://bangbingsyb.blogspot.com/2014/11/leetcode-next-permutation.html
    void nextPermutation(vector<int>& num) {
        if(num.size()<2) return;
        int n = num.size(), j = n-2;
        while(j>=0 && num[j]>=num[j+1]) j--;
        
        if(j<0) {
            sort(num.begin(),num.end());
            return;
        } 
        
        int i=j+1;
        while(i<n && num[i]>num[j]) i++;
        i--;
        
        swap(num[i],num[j]);
        sort(num.begin()+j+1, num.end());
    }
};
//出错原因，由于没有考虑到1 1 5这种情况，需要考虑重复数字
// 基本没问题，编程技巧还有问题，现在不知道怎么应对115 这种情况
/*
while(j<nums.size()&&nums[j]>nums[i])  对应1 5 1 一定是--nums[j]>nums[i]  而不是nums[j]>=nums[i]
等于的情况不可取
*/
// 还是出现115 的情况了，加油， 不会了，然后115的情况又出现了
