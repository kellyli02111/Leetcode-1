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
        int res = 0;
        int n = points.size();
        for(int i = 0; i < n; i++){
            unordered_map<double, int> slopeCount;
            slopeCount[INT_MIN] = 0;
            int duplicate = 1;
            for(int j = i + 1; j < n; j++){
                if((points[i].x == points[j].x) && (points[i].y == points[j].y)){
                    duplicate++;
                }
                else if(points[i].x == points[j].x){
                    slopeCount[INT_MAX]++;
                }
                else{
                    double slope = (double)(points[j].y - points[i].y) / (points[j].x - points[i].x);
                    slopeCount[slope]++;
                }
            }
            for(auto it = slopeCount.begin(); it != slopeCount.end(); it++){
                int numPoints = it->second + duplicate;
                if(numPoints > res){
                    res = numPoints;
                }
            }
        }
        return res;
    }
};
