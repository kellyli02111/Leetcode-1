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
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        //最小堆一定要用三个参数define
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < intervals.size(); i++){
            if(!pq.empty() && pq.top() <= intervals[i].start){
                pq.pop();
            }
            pq.push(intervals[i].end);
        }
        return pq.size();
    }
    
    static bool compare(Interval& a, Interval& b){
        return a.start < b.start;
    }
};
