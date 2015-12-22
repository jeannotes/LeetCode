class Solution {
//https://leetcode.com/problems/powx-n/
public:
    double myPow(double x, int n) {
        if(n==0) return 1;//注意很多细节
        if(n==1) return x;
        if(x==0||x==1) return x;
        
        if(n<0){
            if (n == INT_MIN) {
                return 1;
            }
            return myPow(1.0/x,-n);
        }
        double half = myPow(x, n/2);
        if(n%2==0){
            return half * half;
        }
        return x*half * half;
    }
};
