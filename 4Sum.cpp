class Solution {
public:
//http://www.cnblogs.com/tenosdoit/p/3649607.html  非常好的一篇博客
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        int n=num.size();
        vector<vector<int> > res;
        unordered_map<int,vector<pair<int,int> >>pairs;
        sort(num.begin(),num.end());
        //先保存 前面两数的和
        for(int i=0;i<=n-2;i++){
            for(int j=i+1;j<=n-1;j++){
                pairs[num[i]+num[j]].push_back(make_pair(i,j));
            }
        }
        
        for(int i=0;i<=n-4;i++){
            if(i>0&&num[i]==num[i-1])   continue;//避免重复元素
            for(int j=i+1;j<=n-3;j++){
                if(j>i+1&&num[j]==num[j-1])     continue;
                
                if(pairs.find(target-num[i]-num[j])!=pairs.end()){
                    bool isFirstPush=true;
                    vector< pair<int,int> > sum2=pairs[target-num[i]-num[j]];
                    for(int k=0;k<sum2.size();k++){
                        if(sum2[k].first<=j)     continue;//新找出来的数组索引值一定要大于之前的两个索引值，i，j
                        if(isFirstPush||(res.back())[2]!=num[sum2[k].first]){
                            res.push_back(vector<int>{num[i],num[j],num[sum2[k].first],num[sum2[k].second]});
                            isFirstPush=false;
                            //这里较难理解，因为我第一次可以有重复 1 2 2 3，但是第二次就不行
                            //如果有1 2 2，第四个数字一定是3，就一定会重复
                        }
                    }
                }
            }
        }
        
        return res;
    }
};
//好题目，非常容易出错的
//  注意学会使用 pair语句
//要给自己点赞的，这次是巨大的进步
//小问题不断啊
