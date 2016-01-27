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
