class Solution {
public:
//与 56. Merge Intervals 相同的做法   
    class Compare{
    public:
        bool operator()(const Interval&i1,const Interval&i2){
            return i1.start<i2.start;
        }
    };
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval>res;
        if(intervals.empty()){
            res.push_back(newInterval);
            return res;
        }
        
        Compare cmp;
        intervals.push_back(newInterval);
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
