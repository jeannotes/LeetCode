class Solution {
public:
    class Compare{
        public:
            bool operator()(const Interval &i1,const Interval&i2){
                return i1.start<i2.start;
            }
    };
    
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval>res;
        if(intervals.empty())
            return res;
        Compare cmp;
        sort(intervals.begin(),intervals.end(),cmp);
        res.push_back(intervals[0]);
        
        for(int i=1;i<=intervals.size()-1;i++){
            if(intervals[i].start<=res.back().end)
                res.back().end=max(intervals[i].end,res.back().end);
            else
                res.push_back(intervals[i]);
        }
        return res;
    }
};
//1 4  2 3  这种情况没有考虑到  还有就是operator不会
//operator 不会啊
//operator 这部分函数重载稍微会了一点
