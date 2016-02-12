class smaller {
public:
    bool operator()(pair<int, int> const & p1, pair<int, int> const & p2) {
        return p1.first < p2.first;
    }
};

class Solution {
public:
    int jump(vector<int>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, smaller> pq;
        int n = nums.size();
        if(n < 2) return 0;
        for(int i = 0; i < n; i++){
            pq.push(make_pair(i + nums[i], i));
        }
        int target = n - 1;
        int start = target;
        int step = 0;
        while(target > 0){
            while(!pq.empty() && pq.top().first >= target){
                if(pq.top().second < start){
                    start = pq.top().second;
                }
                pq.pop();
            }
            target = start;
            step++;
        }
        return step;
    }
};
