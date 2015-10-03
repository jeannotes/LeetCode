class Solution {
public:
    void combineHelper(int n,int k,int start,vector<int> &answer,vector<vector<int> >&result){
        if(answer.size()==k){
            result.push_back(answer);
            return;
        }   //answer暂时保存k位数字
        if(start>n){
            return;
        }
        
        answer.push_back(start);
        combineHelper(n,k,start+1,answer,result);
        answer.pop_back();
        //虽然这边写的是删除一个值，但是因为是迭代，所以第一个函数运行到这边的时候，
        //实际相当于把第一次的一整个vector清空，验证这个可以通过把下面的那个语句屏蔽到
        //发现只能生成一组vector。
        //这个程序谨记，第一次遇到。
        //所以下面的值为start+1，而不是start+2.
        combineHelper(n,k,start+1,answer,result);
    }
    
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> >result;
        vector<int>answer;
        combineHelper(n,k,1,answer,result);
        return result;
    }
};
