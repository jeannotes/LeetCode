class Solution1 {
public:
    int mySqrt(int x) {
        if(x<=0)
            return 0;
        if(1<=x&&x<4)
            return 1;
        //不能超过 2147395599，他的根号值是46340，
        //超过了，结果也是 46340 ，
        //所以，最大结果是 46340 ，那么 s<=x/2 x最大也就是46340*2
        if(x>=2*46340)
            return binaryInt(x,1,46340);
        return binaryInt(x,1,x/2);
    }
    
    int binaryInt(int x,int left,int right){
        if(left>right)
            return right;
        int mid=(left+right)/2;
        if(mid*mid==x)
            return mid;
        else if(mid*mid<x)
            return binaryInt(x,mid+1,right);
        else
            return binaryInt(x,left,mid-1);
    }
};

class Solution2 {
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
                if((mid+1)>x/(mid+1))
                /*The key is that midmid will overflow the integer if mid is large enough. 
                Therefore it is better to do mid> x/mid, 
                as that will definitely NOT overflow as long as mid is a valid positive int.
                */
                    return mid;
                else
                    left=mid+1;
            }
        }
    }
};
