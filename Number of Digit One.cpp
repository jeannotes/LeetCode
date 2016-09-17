class Solution {
public:
    int countDigitOne(int n) {
    	if (n < 0)
    		return 0;
    	long long base = 1;
    	int res = 0;
    	while (n>=base){
    		int cur = n / base % 10;
    		int pre = n / base / 10;
    		int end = n%base;
    		if (cur == 1) {
    			res += pre*base + end + 1;
    		}
    		else if (cur == 0) {
    			res += pre*base;
    		}
    		else {
    			res += pre*base + base;
    		}
    		base = base * 10;
    	}
    	return res;
    }
};
//http://blog.csdn.net/u013027996/article/details/17126977
//https://discuss.leetcode.com/topic/18146/my-ac-java-solution-with-explanation/2
//  这是好题目这是好题目啊,still kind of difficult
