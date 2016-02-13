class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int minIdx = 0;
        int minVal = INT_MAX;
        int sum = 0;
        for(int i = 0; i < n; i++){
            gas[i] = gas[i] - cost[i];
            sum = sum + gas[i];
            if(sum < minVal){
                minVal = sum;
                minIdx = i;
            }
        }
        if(sum < 0) return -1;
        return (minIdx + 1) % n;
    }
};
