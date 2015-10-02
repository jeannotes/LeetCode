typedef long long ll;
class Solution {
public:
//https://leetcode.com/problems/divide-two-integers/
    int divide(int dividend, int divisor) {
        ll a = dividend >= 0 ? dividend : -(ll)dividend;
        ll b = divisor >= 0 ? divisor : -(ll)divisor;
        ll result = 0, c = 0;
        bool sign = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0);

        while(a>=b){
            c=b;
            for(int i=0;a>=c;i++,c<<=1){//c<<suoy=1,每一次这个操作就会使得除数*2。因为他是迭代的，
                                        //所以循环内部是+(1<<i)-->代表多少个倍数的除数。
                a=a-c;
                result=result+(1<<i);
            }
        }
        if (sign) {
            return max((ll)INT_MIN, -result);
        } else {
            return min((ll)INT_MAX, result);
        }
    }
};
