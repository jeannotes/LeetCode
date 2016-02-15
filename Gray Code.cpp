class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res(1,0);
        for(int i=0;i<n;i++){
            int curCount=res.size();
            while(curCount){
                curCount--;
                int curNum=res[curCount];//0 1 3 2
                curNum+=(1<<i);
                res.push_back(curNum);
            }
        }
        return res;
    }
};
//大神还是很多的，代码就是好看
