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
// 好久没有做这题了  怒做python
class Solution:
    def getKth(self,A,B,k):
        m, n = len(A), len(B)
        if m > n:
            return self.getKth(B, A, k)
        if m == 0:
            return B[k - 1]
        if k == 1:## 这个地方忘记了
            return min(A[0], B[0])
        pa=min(k/2,m)
        pb=k-pa
        if A[pa-1]<=B[pb-1]:
            return self.getKth(A[pa:],B,pb)
        else:
            return self.getKth(A,B[pb:],pa)
    
    def findMedianSortedArrays(self,A,B):
        m,n=len(A),len(B)
        if (m+n)%2==1:
            return self.getKth(A,B,(m+n)/2+1)
        else:
            return (self.getKth(A,B,(m+n)/2)+self.getKth(A,B,(m+n)/2+1))*0.5
