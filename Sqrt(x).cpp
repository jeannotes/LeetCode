class Solution {
    //https://leetcode.com/discuss/24942/a-binary-search-solution
public:
    int mySqrt(int x) {
        if(x<=1)
            return x;
        int left=1,right=x;
        while(true){
            int mid=(left+right)/2;
            if(mid>x/mid)
                right=mid-1;
            else{
                /*The key is that midmid will overflow the integer if mid is large enough. 
                Therefore it is better to do mid> x/mid, 
                as that will definitely NOT overflow as long as mid is a valid positive int.
                */
                if((mid+1)>x/(mid+1))
                    return mid;
                else
                    left=mid+1;
            }
        }
    }
};
