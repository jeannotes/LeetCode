class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
            return 1;
        if(x==0||x==1)
            return x;
        if(n<0){
            if(n==INT_MIN)
                return 1;
            return myPow(1.0/x,-n);
        }
        return n%2==0? myPow(x*x,n/2):x*myPow(x*x,n/2);   
    }
};
//还是不会，究其原因，可以这样理解不要考虑正向最大值，因为会不断的除以2，但是需要考虑的是
//当n为负数无穷大，为什么结果是1
