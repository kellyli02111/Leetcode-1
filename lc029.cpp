class Solution {
public:
    int divide(int dividend, int divisor) {
        bool pos = 1;
        long long res = 0;
        if(dividend < 0) pos = !pos;
        if(divisor < 0) pos = !pos;
        if(divisor == 0) return INT_MAX;
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        long long a = dividend;
        long long b = divisor;
        a = abs(a);
        b = abs(b);
        while(a >= b){
            long long t = b;
            long long tempRes = 1;
            while(a >= t){
                t = t << 1;
                tempRes = tempRes << 1;
            }
            t = t >> 1;
            tempRes = tempRes >> 1;
            a = a - t;
            res = res + tempRes;
        }
        if(pos) return res;
        else return -res;
    }
};
