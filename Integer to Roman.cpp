class Solution {
public:
    string intToRoman(int num) {
        string roms[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        //如何想到这些方法的，罗马数字的排列还是很有规律的。
        int nums[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string res;
        for(int i=0;i<13&&num>0;i++){
            while(num>=nums[i]){
                res+=roms[i];
                num-=nums[i];
            }
        }
        return res;
    }
};
