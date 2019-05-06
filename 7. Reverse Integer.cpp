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
/*
2^31 = 2147483648
*/
