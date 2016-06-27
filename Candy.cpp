class Solution1 {
    //https://leetcode.com/problems/candy/
public:
//第一种解法
    int candy(vector<int>& ratings) {
        if(ratings.empty()) return 0;
        int n = ratings.size();
        vector<int> table(n, 1);
        
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]) table[i]=table[i-1]+1;
        }
        int res=table[n-1];
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]&&table[i]<=table[i+1])   table[i]=table[i+1]+1;
            //杜绝 1 2 1 现象的发生
            res+=table[i];
        }
        return res;
    }
};

class Solution2 {
public:
//第二种解法
    int candy(vector<int>& ratings) {
        if(ratings.empty()) return 0;
        int n = ratings.size();
        vector<int> table(n, 1);
        
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]) table[i]=table[i-1]+1;
        }
        int res=table[n-1];
        for(int i=n-2;i>=0;i--){
            int cur=1;
            if(ratings[i]>ratings[i+1]){
                cur=table[i+1]+1;
            }
            res+=max(cur,table[i]);
            table[i]=max(cur,table[i])
            //table[i]=cur 或者  table[i]=max(cur,table[i]) 均可
            // 没有“table[i]=cur;”  对 [1,3,1] 无影响
        }
        
        return res;
    }
};
//第二种解法不知道，第一种方法较好，但是要判断&&table[i]<=table[i+1]，因为已经前面比后面大的话，没有必要加1啦
//  一次AC，不准备再做了
