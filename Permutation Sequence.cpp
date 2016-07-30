class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>nums(9,0);
        int s[9];
        
        for(int i=0;i<9;i++){
            nums[i]=i+1;   //nums 存放1--n
            s[i]=(i>0)?(i+1)*s[i-1]:1;//s[i] 存放各个数字的阶乘
        }
        k--;
        
        string ret("");
        for(int i=n;i>=1;i--){
            if(i-2<0){
                ret+=char('0'+nums[0]);//这边不能写nums[i-1]  ，因为最后面会缩减nums数组
                return ret;
            }
            int tmp=k/s[i-2];
            ret+=char('0'+nums[tmp]);
            //把从tmp开始的数，从后面往前面移动
            for(int j=tmp+1;j<n;j++)
                nums[j-1]=nums[j];//至此 nums数组重新生成,I understand it now thoroughly!
            k=k%s[i-2];
        }
        return ret;
    }
};
//不会啊
//add binary 中是强制转换为数字的时候用减号  强制字符的时候用加号
//不会了啊，然而我还是不会啊，第二天做，还是各种小错误
