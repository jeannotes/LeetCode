class Solution {
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
