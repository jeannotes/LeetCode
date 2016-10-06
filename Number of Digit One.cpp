class Solution {
public:
    int countDigitOne(int n) {
        if (n <= 0)
            return 0;
        long long base = 1;
        int res = 0;
        while (n>=base){
            int cur = n / base % 10;
            int pre = n / base / 10;
            int end = n%base;

            if (cur == 1) {
                //32145
                res += pre*base + end + 1;
                // 可以认为是 00100-00199 01100-01199 .. 31100-31199 
                // 不是还剩下以32的开头嘛，加上45+1
                // 此时就只能32100-32145 了 
            }
            else if (cur == 0) {
                res += pre*base;
            }
            else {
                //32245 32345
                // 此时就  32100-32199 了 多加个 base倍数
                res += pre*base + base;
            }
            base=base*10;
        }
        return res;
    }
};
//http://blog.csdn.net/u013027996/article/details/17126977
//https://discuss.leetcode.com/topic/18146/my-ac-java-solution-with-explanation/2
//  这是好题目这是好题目啊,still kind of difficult 换上一个有注释的版本
