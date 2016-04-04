class Solution {
public:
    double myPow(double x, int n) {
    	if (x==0){
    		return x;
    	}
    	if (n==0){
    		return 1;
    	}
    
    	if (n<0){
    	    if(n==INT_MIN)
    	    	return 1.0/(myPow(x,INT_MAX)*x);
    	    else    
    	        return myPow(1.0/x,-n);
    	}
    
    	return n%2==0?(myPow(x*x,n/2)):(myPow(x*x,n/2)*x);
    }
};
//用位运算代替乘除和求余优化效率：移位代替除法（n>>1 == n /2);用位与代替求余判定奇偶（if (n& 0x1 == 1) == if(n % 2 == 1))

//对于n取值INT_MIN = -2147483648时，-n依然是INT_MIN，并不是INT_MAX=2147483647，这时需要格外小心。
//  还是不会啊
