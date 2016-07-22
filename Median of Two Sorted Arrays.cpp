class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len=nums1.size()+nums2.size();
        
        if(len%2)//奇数
            return  findKthElement( nums1 ,nums2 , (len+1)/2 ) ;
        else//偶数    
            return  (findKthElement(nums1,nums2,len/2)+findKthElement( nums1 , nums2 , len/2+1 ))*0.5 ;
    }
    
    double min(double x,double y){
        return x<y?x:y;
    }
    
    double findKthElement(vector<int>& nums1,vector<int>& nums2,int k){
        if(nums1.size()>nums2.size()){
            return findKthElement(nums2,nums1,k);
        }
        
        if(nums1.empty())   return nums2[k-1];
        if(nums2.empty())   return nums1[k-1];
        
        if(k==1)    return min(nums1[0],nums2[0]);
        
        int ia=min(k/2,nums1.size());
        int ib=k-ia;
        if(nums1[ia-1]<nums2[ib-1]){
            vector<int> new_nums1(nums1.begin()+ia,nums1.end());
            return findKthElement( new_nums1 , nums2 , k-ia ) ;
        }if(nums1[ia-1]>nums2[ib-1]){
            vector<int> new_nums2(nums2.begin()+ib,nums2.end());
            return findKthElement( nums1 , new_nums2 , k-ib ) ;
        }
        return nums1[ia-1];
    }
};
// 好久没有做这题了
