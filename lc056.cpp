/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool smaller(Interval a, Interval b){
    return a.start < b.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n < 2){
            return intervals;
        }
        vector<Interval> res;
        sort(intervals.begin(), intervals.end(), smaller);
        res.push_back(intervals[0]);
        for(int i = 1; i < n; i++){
            if(intervals[i].start <= res.back().end){
                res.back().end = max(intervals[i].end, res.back().end);
            }
            else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
