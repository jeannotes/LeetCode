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
//不会
//第二天早上练习的，不太会
//不会
// 有瑕疵啊，加油
// 还不错
