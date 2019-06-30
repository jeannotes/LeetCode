//与 56. Merge Intervals 相同的做法   
class Solution {
public:
    static bool comparator( vector<int>& a, vector<int>& b ){
        return a[0] < b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if( intervals.empty() )  return res; 
        
        if( intervals.size() == 1 )  {
            res.push_back( intervals[0]);
            return res;
        }
        
        sort( intervals.begin(), intervals.end(), comparator );
        
        //Push the first interval into the result
        res.push_back( intervals[0] );
        int i = 1;
        while( i < intervals.size() ){
            vector<int>& last = res.back();
            //Check for overlapping boundaries in the intervals and merge them suitably
            if( last[1] < intervals[i][0] ) {
                res.push_back( intervals[i] );
            }else            {
                last[1] = max( last[1], intervals[i][1] );
            }
            i++;
        }
        
        return res;
    }    
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }
};
//上面一题不会，这一题也不会
// 小毛病太多
// 问题不大的
