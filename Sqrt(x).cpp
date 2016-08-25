    //https://leetcode.com/discuss/24942/a-binary-search-solution
class Solution {
public:
    int mySqrt(int x) {
		if (x==0||x==1){
			return x;
		}
		int i=1,j=x/2;
		while (i<=j){
			int mid=(i+j)/2;
			if (mid*mid==x){
				return mid;
			}else if (mid>x/mid){
				j=mid-1;
			}else{/*The key is that midmid will overflow the integer if mid is large enough. 
                Therefore it is better to do mid> x/mid, 
                as that will definitely NOT overflow as long as mid is a valid positive int.
                */
				if ((mid+1)>x/(mid+1)){
					return mid;
				}else
					i=mid+1;
			}

		}
	}
}; 
class Solution2 {
public:
    int mySqrt(int x) {

        int p = 0, q = x;
        while(p < q)
        {
            // Basically, q = (p+q)/2. Code like below has two purpose: 
            // 1) avoid overflow.
            // 2) handle corner case, such as x = 1, prevent divided-by-zero error for p=x/q.
            q = max(1, p + (q - p) / 2);  
            p = x / q;
        }

        return p > q ?  q: p; // if the loop exits because p > q, return q; otherwise, p is the answer.
    }
};
// 还不错
// 新方法更好，解决问题更加简洁，如果p=q  直接返回p  如果p>q 就说明出现(mid+1)>x/(mid+1)  这个时候返回q
//  好题目啊，第二遍做还是不会啊 i<=j 这边的等于号没有加上去
