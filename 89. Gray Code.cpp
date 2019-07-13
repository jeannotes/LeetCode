class Solution {
public:
    vector<int> grayCode(int n) {
		vector<int> res;
		res.push_back(0);
		for (int i=1;i<=n;i++){
			int j=1<<(i-1);// not i
			for (int k=res.size()-1;k>=0;k--){
				res.push_back(res[k]+j);
			}
		}
		return res;
	}
};
