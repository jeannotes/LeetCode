#include "iostream"
#include "cstdio"
#include "cstring"
#include "stack"
#include "algorithm"

using namespace std;

class Solution
{
public:
	int longestValidParentheses(string s){
		stack<int> st;
		int result=0,accu=0;

		for (int i=0;i<s.size();i++){
			if (s[i]=='('){
				st.push(i);
			}
			else{
				if (st.empty()){
					accu=0;
				}
				else {
					int j=st.top();
					st.pop();
					if (st.empty()){
						accu+=i-j+1;
						result=max(accu,result);
					}
					else {
						result=max(i-j+1,result);
					}
				}
			}
		}
	return result;
	}
};


int main(){
	string test;
	Solution s;
	while (cin>>test){
		cout<<s.longestValidParentheses(test)<<endl;
	}
}

