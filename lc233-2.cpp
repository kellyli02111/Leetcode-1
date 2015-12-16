class Solution {
public:
    int countDigitOne(int n) {
        long long res = 0;
        int highn = n;
        int lowc = 1;
        int lown = 0;
        while(highn > 0){
            int curn = highn % 10;
            highn = highn / 10;
            if(curn > 1){
                res = res + (highn + 1) * lowc;
            }
            else if(curn == 1){
                res = res + highn * lowc;
                res = res + lown + 1;
            }
            else{
                res = res + highn * lowc;
            }
            lown = curn * lowc + lown;
            lowc = lowc * 10;
        }
        return res;
    }
};
