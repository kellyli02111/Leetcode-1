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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        int n = intervals.size();
        bool inserted = false;
        for(int i = 0; i < n; i++){
            if(inserted == true){
                res.push_back(intervals[i]);
                continue;
            }
            if(newInterval.end < intervals[i].start){
                res.push_back(newInterval);
                res.push_back(intervals[i]);
                inserted = true;
                continue;
            }
            if((newInterval.start <= intervals[i].end) && (intervals[i].start <= newInterval.end)){
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
                continue;
            }
            if(newInterval.start > intervals[i].end){
                res.push_back(intervals[i]);
                continue;
            }
        }
        if(inserted == false){
            res.push_back(newInterval);
        }
        return res;
    }
};
