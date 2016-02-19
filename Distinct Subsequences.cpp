class Solution {
public:
    int numDistinct(string s, string t) {
		if (s.empty()){
			return 0;
		}
		if (t.empty()){
			return 1;
		}

		int len1=s.size(),len2=t.size();
		int res[len1+1][len2+1];
		res[0][0]=1;
		for (int i=1;i<=len1;i++){
			res[i][0]=1;
		}
		for (int i=1;i<=len2;i++){
			res[0][i]=0;
		}
		for (int i=1;i<=len1;i++){
			for (int j=1;j<=len2;j++){
				if (s[i-1]==t[j-1]){
					res[i][j]=res[i-1][j-1]+res[i-1][j];
				}else
					res[i][j]=res[i-1][j];
			}
		}
		return res[len1][len2];
	}
};
// 这题目值得注意的是，题目说 t的substring在s中的个数，所以如果当前字符不相同，
//那我t的子字符串，可以不算上当前的字符，意思就是至少要加上s前面的一部分，也就是+res[i-1][j];
