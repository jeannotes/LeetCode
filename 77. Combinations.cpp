class Solution {
public:
    vector<vector<int>>res;
    vector<int>tem;
    vector<vector<int>> combine(int n, int k) {
        combineHelper(1,n,k);
        return res;
    }
    
    void combineHelper(int start,int n,int k){
        /*
        if(start>n-k+1){//这一段不能要，因为会使得后面的 13 14 15全部消失。n=4，k=2的情况
            return;
        }*/
        if(tem.size()==k){
            res.push_back(tem);
            return;
        }
        if(start>n)
            return;//加上这句话是有必要的，但是放在前面还不行
        for(int i=start;i<=n;i++){
            tem.push_back(i);
            combineHelper(i+1,n,k);
            tem.pop_back();
        }
    }
};
//不会
// if(start>n)  这句话没有判断
class Solution {
public:
    vector<vector<int>> res;
    vector<int>temp;
    vector<vector<int>> combine(int n, int k) {
        if(n==0) return res;
        combineHelper(n,k,1,0);
        
        return res;
    }
    
    void combineHelper(int n, int k, int start,int index){
        if(index == k){
            res.push_back(temp);
            return;
        }
        for(int i=start;i<=n;i++){
            temp.push_back(i);
            combineHelper(n,k,i+1,index+1);
            temp.pop_back();
        }
    }
};
//我的另外一个解法
// 可以的，首先 我是能够得到[1 2],我担心的是不能得到[1 3]
//但是 其实是可以的，因为最后 ..helper(i+1,..) 这本身就会有好几种情况，他自身也是循环，也存在[2] [3]等等
