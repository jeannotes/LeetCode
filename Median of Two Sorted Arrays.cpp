class Solution {
public:
//O(M + N) operation
    
    double min(double a, double b) {
        return a > b ? b : a;
    }

    double findKthElement(vector<int>& nums1, vector<int>& nums2,int k) {
        if(nums1.size()>nums2.size()){
            return findKthElement(nums2, nums1,k);
        }
        //处理有一边是空的情况
        if(nums1.empty())   return nums2[k-1];
        if(nums2.empty())   return nums1[k-1];
        
        if(k==1)    return min(nums1[0],nums2[0]);
        
        int ia=min(k/2,nums1.size());
        int ib=k-ia;
        
        if(nums1[ia-1]<nums2[ib-1]){//前面ia个数都是没用的
            vector<int> v(nums1.begin()+ia,nums1.end());
            return findKthElement(v, nums2,k-ia);//本来找第k大的，前面ia个没用，自然变成找k-ia大的。
        }
        if(nums1[ia-1]>nums2[ib-1]){//前面ia个数都是没用的
            vector<int> v(nums2.begin()+ia,nums2.end());
            return findKthElement(nums1, v,k-ia);//本来找第k大的，前面ia个没用，自然变成找k-ia大的。
        }
        
        return nums1[ia-1];
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len=nums1.size()+nums2.size();
        
        if(len&0x01){//奇数个
            return findKthElement(nums1,nums2,(len+1)/2);
        }else{
            return (findKthElement(nums1,nums2,len/2)+findKthElement(nums1,nums2,len/2+1))*0.5;
        }
    }
};
