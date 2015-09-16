//北大老师称之为地推
//在网上看了好多的版本，其实这就是动态规划，只不过不要从上而下（对于本题）
//动归最好从能够理解的那一层次开始，即从最开始的地方的那一层开始.
//https://leetcode.com/problems/triangle/
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


