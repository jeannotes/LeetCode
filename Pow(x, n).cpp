double myPow(double x, int n) {
	if (x == 0||n==0)
		return 1;
	if (n < 0) {
		if (n == INT_MIN)
			return 1.0/(myPow(x,INT_MAX)*x);
		return myPow(1.0 / x, -n);
	}

	if (n % 2)
		return myPow(x*x, n / 2)*x;
	return myPow(x*x, n / 2);
}
//用位运算代替乘除和求余优化效率：移位代替除法（n>>1 == n /2);用位与代替求余判定奇偶（if (n& 0x1 == 1) == if(n % 2 == 1))

//对于n取值INT_MIN = -2147483648时，-n依然是INT_MIN，并不是INT_MAX=2147483647，这时需要格外小心。
//  还是不会啊，今天还行啊，加油,once again ,this is brilliant
// 今天这遍还行，这一块还是没能够做出来啊
// return 1.0/(myPow(x,INT_MAX)*x);这边 没有注意到啊
