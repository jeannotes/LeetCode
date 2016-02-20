class Solution {
public:
//https://leetcode.com/problems/word-break-ii/
	void breakHelper(string &s,int index,vector<vector<int> > &Br,vector<string> &answer,vector<string> &result){
		if (index<0){
			//append()函数用来将一个字符串连接在另一个字符串的后面
			string r(answer[answer.size()-1]);
			for (int i=answer.size()-2;i>=0;i--){
				r.push_back(' ');
				r.append(answer[i]);
			}
			result.push_back(r);
			return ;
		}
		//index<0 的时候先不考虑

		//这个时候Br二维数组最后一行存放的就是能够分开的索引值，比如说4,5,8
		//应该来说，是各种各样的，可能从2能分开，4也能分开，可能0-4就是一组
		//如果这样，i=4，就说明从4-n就在数组里面
		for (int i=0;i<Br[index].size();i++){
			int start=Br[index][i];//这个就代表从start开始到最后，是完全能够找得到，都在dict里面
			answer.push_back(s.substr(start,index-start+1));
			breakHelper(s,start-1,Br,answer,result);//因为start到n都能找到，所以开始找0-start-1的
			answer.pop_back();//他这个是很多个循环，最后一次i之后全部清空，方便下次再进入			
		}
	}


	vector<string> wordBreak(string s, unordered_set<string> &dict) {
		//程序的一个意思就是，在一个大循环i里面,再设置一个小循环j
		//数组Br[i][j]代表从j到i可以分开，且在之前的都没有问题
		//条件就是从j到i能够在提供的所有字符串中找到，且Br[j-1]不为空---意思就是我从0到j也能够被分割，至于存放啥，不管。

		vector<string> result;

		if(s.empty()){
			result.push_back("");
			return result;
		}

		const int n=s.size();
		vector <vector <int> >Br(n,vector<int>());

		for (int i=0;i<n;i++){
			for (int j=i;j>=0;j--){
				if (dict.find(s.substr(j,i-j+1))!=dict.end()&&(j==0||!Br[j-1].empty())){
					//从j开始
					Br[i].push_back(j);
				}
			}
		}

		vector<string> answer;
		breakHelper(s,n-1,Br,answer,result);
		return result;
	}
};
