class Solution
{
//https://leetcode.com/problems/subsets/
public:
	vector<vector<int> >subsets( vector<int> & S){
		vector<vector <int> > result;
		result.push_back(vector<int>());
		
		sort(S.begin(),S.end());

		for (int i=0;i<S.size();i++){
			int count=result.size();
			for (int j=0;j<count;j++){
				result.push_back(result[j]);//从头到尾一个个依次复制
				                            //具体的二维数组还要多看下概念，
				                            //目前感觉result.push_back(result[j])就是另起一行，
				                            //result[j]就是在第j行后面压入堆栈
				result[count+j].push_back(S[i]);//就是前面刚刚复制过得
												//加上第i位数字
				//其实意思就是对于前一位，先是一个个按照j的顺序复制，到循环结束
				//正好复制完毕，而没复制一个，就在后面加上S[i]
				//程序巧妙在于，前面count行的字符串没有变化。
				//正好循环结束，最后一行也把最后一个S[i]复制完毕
			}
		}
		return result;
	}
};
