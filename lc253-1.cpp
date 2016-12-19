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
        map<int, int> m;
        for(int i = 0; i < intervals.size(); i++){
            m[intervals[i].start]++;
            m[intervals[i].end]--;
        }
        int res = 0;
        int rooms = 0;
        for(map<int, int>::iterator it = m.begin(); it != m.end(); it++){
            rooms = rooms + it->second;
            res = max(res, rooms);
        }
        return res;
    }
};
