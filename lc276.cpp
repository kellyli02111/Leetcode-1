class Solution {
public:
    int numWays(int n, int k) {
        if(n == 0 || k == 0) return 0;
        if(n == 1) return k;
        int curS = k;
        int curD = k * (k - 1);
        for(int i = 2; i < n; i++){
            int tempS = curD;
            int tempD = (k - 1) * (curS + curD);
            curS = tempS;
            curD = tempD;
        }
        return (curS + curD);
    }
};
