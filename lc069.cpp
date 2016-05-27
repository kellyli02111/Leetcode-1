class Solution {
public:
    int mySqrt(int x) {
        long long val = x;
        long long begin = 0;
        long long end = 50000;
        while(begin < end){
            long long mid = (begin + end) / 2;
            long long midSq = mid * mid;
            long long midPlusOneSq = (mid + 1) * (mid + 1);
            if(midSq == x) return mid;
            else if(midSq > x){
                end = mid - 1;
            }
            else if(midPlusOneSq > x){
                return mid;
            }
            else{
                begin = mid + 1;
            }
        }
        return begin;
    }
};
