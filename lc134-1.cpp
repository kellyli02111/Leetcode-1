class Solution {
public:
    int convert(int i, int n){
        return i % n;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int start = 0;
        int end = 0;
        int curGas = 0;
        while(end - start <= n){
            if(start == n) return -1;
            if(curGas >= 0){
                curGas = curGas + gas[convert(end, n)] - cost[convert(end, n)];
                end++;
                continue;
            }
            else{
                curGas = curGas - gas[convert(start, n)] + cost[convert(start, n)];
                start++;
                /*if(end < start){
                    end = start;
                    curGas = 0;
                }*/
                continue;
            }
        }
        return start;
    }
};
