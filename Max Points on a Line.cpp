/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if(points.empty())  return 0;
        
        int n=points.size();
        int result=0;
        
        for(int i=0;i<n;i++){
            unordered_map<double,int> counter;
            int same=1;
            int ver=1;
            int maxCount=0;
            
            for(int j=i+1;j<n;j++){
                if(points[i].x==points[j].x&&points[i].y==points[j].y){
                    //这个时候是同一个点
                    same++;
                    ver++;
                }else if(points[i].x==points[j].x){
                    ver++;
                }else{
                    double slope=1.0*(points[i].y-points[j].y)/(points[i].x-points[j].x);
                    //这个地方不写1.0*....就是错误啊
                    ++counter[slope];
                    if(counter[slope]>maxCount)   maxCount=counter[slope];
                }
            }
            maxCount+=same;
            if(maxCount<ver)    maxCount=ver;
            if(maxCount>result) result=maxCount;
        }
        
        return result;
    }
};
