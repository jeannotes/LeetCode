class Solution1 {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> result;

		const int n = intervals.size();
        if (n == 0) {
            result.push_back(newInterval);
            return result;
        }
		if (newInterval.start > intervals[n-1].end) {
            result = intervals;
            result.push_back(newInterval);
            return result;
        }
        if (newInterval.end < intervals[0].start) {
            result.push_back(newInterval);
            result.insert(result.end(), intervals.begin(), intervals.end());
            return result;
        }
		//头尾考虑结束

		int i = 0;
        while (newInterval.start > intervals[i].end) {
            result.push_back(intervals[i++]);
        }
        
        int j = n - 1;
        while (newInterval.end < intervals[j].start) {
            j--;
        }

        if (j < i) {
            result.push_back(newInterval);//对应加在中间的情况，无重叠
        }
        else {
            newInterval.start = min(newInterval.start, intervals[i].start);
            //这个时候生成新的区间了，所以是result[i]
            newInterval.end = max(newInterval.end, intervals[j].end);
            result.push_back(newInterval);
        }//有可能是一个大的跨度，所以为j
		
		result.insert(result.end(),intervals.begin()+j+1,intervals.end());
		return result;
	}
};


class Solution2 {
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
        intervals.push_back(newInterval);  
        Compare cmp;
        sort(intervals.begin(),intervals.end(),cmp);
        res.push_back(intervals[0]);
        
        for(int i=1;i<intervals.size();i++){
            if(res.back().end<intervals[i].start)
                res.push_back(intervals[i]);
            else
                res.back().end=max(res.back().end,intervals[i].end);
        }
        
        return res;
    }
};
