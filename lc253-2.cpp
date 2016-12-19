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
        vector<int> startTime;
        vector<int> endTime;
        for(int i = 0; i < intervals.size(); i++){
            startTime.push_back(intervals[i].start);
            endTime.push_back(intervals[i].end);
        }
        sort(startTime.begin(), startTime.end());
        sort(endTime.begin(), endTime.end());
        int res = 0;
        int endPos = 0;
        for(int i = 0; i < intervals.size(); i++){
            //需要一个新的会议室
            if(startTime[i] < endTime[endPos]){
                res++;
            }
            //上一个end time抵消，新的startTime不需要新的会议室
            else{
                endPos++;
            }
        }
        return res;
    }
};
