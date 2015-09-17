class Solution
{
public:
	vector<vector<int> >subsetsWithDup( vector<int> & S){
		//http://www.cnblogs.com/felixfang/p/3775712.html
		//https://leetcode.com/problems/subsets-ii/
		vector<vector <int> > result;
		result.push_back(vector<int>());

		if (S.empty()){
			return result;
		}

		sort(S.begin(),S.end());
		result.push_back(vector<int>({S[0]}));
		//这一步骤主要是为了从i=1开始，不然就要在程序里面专门设置i=1的模块。

		int lastStart=1;
		//这一步主要是 [1 1], [] [1] [1 1].

		for (int i=1;i<S.size();i++){
			int count=result.size();
			int j=(S[i]==S[i-1]?lastStart:0);//寻找上一次多余的

			for (;j<count;j++){
				result.push_back(result[j]);
				result.back().push_back(S[i]);
				//这个地方不能使用result[count+j].push_back(S[i]);
				//因为不是每一次添加元素都从j处开始添加，j不一定为0.
				//要从多余的开始添加，正好每来一个，在末尾添加。
			}
			lastStart=count;//正好记录多余的
		}
		return result;
	}
};
