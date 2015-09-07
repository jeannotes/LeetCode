class Solution
{
public:
	vector< vector< int > > generate(int numRows){
		vector< vector <int > >triangle;
		for (int i = 0; i < numRows; i++)
		{
			vector<int> v;
			if (i==0)
			{
				v.push_back(1);
			}
			else
			{
				v.push_back(1);
				for (int j = 1; j <= i-1; j++)
				{
					v.push_back(triangle[i-1][j]+triangle[i-1][j-1]);
				}
				v.push_back(1);
			}
			triangle.push_back(v);
		}
		
		return triangle;
	}
};

//第二次编写，还是一些c++语法不太懂，基础很重要，不过，我认为这些无所谓。
//后期我会用c重新编写。
