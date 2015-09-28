class Solution1 {
public:
//https://leetcode.com/problems/sqrtx/
    int mySqrt(int x) {
        if(x<=0) return 0;
        if(x<4) return 1;
        //尤其注意这些地方越界。
        if(x/2>=46340){
            return binaryLowInt(x,0,46340);
        }
        return binaryLowInt(x,0,x/2);    
        
    }
    
    int binaryLowInt(int x,int left,int right){
        if(left>right){
            return right;
        }
        int mid=(left+right)/2;
        if(mid*mid==x){
            return mid;
        }
        if(mid*mid>x){
            return binaryLowInt(x,left,mid-1);
        }
        if(mid*mid<x){
            return binaryLowInt(x,mid+1,right);
        }
    }
};
