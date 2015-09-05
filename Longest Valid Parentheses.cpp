class Solution
{
public:
	int longestValidParentheses(string s){
		stack<int> stk;
		int result=0,accu=0;
		for (int i=0;i<s.size();i++){
			if (s[i]=='('){
				stk.push(i);//存放不能配对的索引。
			}
			else{
				if (stk.empty()){
					accu=0;//重新确定初始位置
				}
				else{
					int j=stk.top();
					stk.pop();
					if(stk.empty()){
						accu+=i-j+1;
						result=max(result,accu);
					}
					else
						result=max(result,i-stk.top());
				}
			}
		}
		return result;
	} 

protected:
private:
};
