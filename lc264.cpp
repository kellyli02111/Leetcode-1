class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglys(1, 1);
        int p2 = 0;
        int p3 = 0;
        int p5 = 0;
        int count = 1;
        while(count < n){
            int nextUgly = min(min(2 * uglys[p2], 3 * uglys[p3]), 5 * uglys[p5]);
            if(nextUgly > uglys.back()){
                uglys.push_back(nextUgly);
                count++;
            }
            if(nextUgly == 2 * uglys[p2]) p2++;
            else if(nextUgly == 3 * uglys[p3]) p3++;
            else p5++;
        }
        return uglys[n - 1];
    }
};
