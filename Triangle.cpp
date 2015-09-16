//地推
class Solution
{
public:
	int minimumTotal(vector< vector<int> > &triangle ){
		if (triangle.empty()){
			//如果为空，返回1
			return 0;
		}

		int n=triangle.size();
		vector <int> row=triangle[n-1];

		for (int i=n-2;i>=0;i--){
			for (int j=0;j<=n;j++){
				row[j]=min(row[j]+row[j+1])+triangle[i][j];
			}
		}
		return row[0];
	}
};



//动态规划
