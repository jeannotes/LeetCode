class Solution {
public:
    int reverse(int x) {
    	if (x<0){
    		return x==INT_MIN?0:-reverse(-x);
    	}
    	int res=0;
    	while (x>0){
    		if (res>INT_MAX/10||(res==INT_MAX/10&&x>7)){
    			return 0;
    		}
    		res=res*10+x%10;
    		x=x/10;
    	}
    	return res;
    }
};
//有小瑕疵
//溢出的条件  返回应该是0
//  溢出的条件  返回应该是0  想要做到bugfree挺难啊
// 然而还是不会了啊,晚上全部出错。
