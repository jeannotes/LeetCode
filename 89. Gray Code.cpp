class Solution {
public:
    vector<int> grayCode(int n) {
		vector<int> res;
		res.push_back(0);
		for (int i=1;i<=n;i++){
			int j=1<<(i-1);
			for (int k=res.size()-1;k>=0;k--){
				res.push_back(res[k]+j);
			}
		}
		return res;
	}
};
//大神还是很多的，代码就是好看
//  int j=1<<(i-1);  这个才是乘以2啊，加油
//  首先写的不顺利 还有就是 1<<(i-1)  写成  2<<(i-1) 
//  首先写的不顺利 还有就是 1<<(i-1)  写成  2<<(i-1)   还是这个老毛病啊
