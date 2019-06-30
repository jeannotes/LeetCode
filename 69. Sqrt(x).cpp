class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;

        while (low < high)
        {
            long long mid = (high - low) / 2 + low;

            if (mid * mid == x)
                return mid;
            else if (mid * mid > x)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low * low > x ? low - 1 : low;
    }
};
// 还不错
// 新方法更好，解决问题更加简洁，如果p=q  直接返回p  如果p>q 就说明出现(mid+1)>x/(mid+1)  这个时候返回q
//  好题目啊，第二遍做还是不会啊 i<=j 这边的等于号没有加上去
