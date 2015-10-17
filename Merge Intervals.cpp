/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:

    class Compare {
    public:
        bool operator() (const Interval &i1, const Interval i2) {
            return i1.start < i2.start;
        }
    };
    
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if(intervals.empty()){
            return result;
        }
        Compare cmp;
        sort(intervals.begin(),intervals.end(),cmp);//按照开头数字升序排列
        //注意考虑两个区间合并后，他的end比下一个的start还要大
        int i=0;
        int k=0;
        result.push_back(intervals[0]);//记住加入第一个数据。
        for(int i=1;i<intervals.size();i++){
            if(intervals[i].start>result.back().end){
                result.push_back(intervals[i]);
            }else{
                //此时注意两种情况，但是总之是有交集的
                result.back().end=max(  result.back().end,intervals[i].end  );
            }
        }
        return result;
    }
};
