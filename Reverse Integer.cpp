class Solution {
public:
//for more information,please email:j.z.feng@foxmail.com
    int reverse(int x) {
        if(x<0){
            return x==INT_MIN ? 0 : -reverse(-x);
        }
        int y,result=0;
        //x=32767
        if(x==0){
            return 0;
        }
        while(x>0){
            if(result>INT_MAX/10){
                return 0;
            }
            if(result==INT_MAX/10 && (x%10)>7){
                return 0;
            }
            result=result*10+(x%10);
            x=x/10;
        }
        return result;
    }
};
