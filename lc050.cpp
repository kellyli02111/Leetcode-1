class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0.0) return 0.0;
        if(n == 0) return 1.0;
        if(n == 1) return x;
        if(n == -1) return 1 / x;
        if (n % 2 == 0){
            return myPow(x * x, n / 2);
        }
        else{
            if(n > 0){
                return x * myPow(x * x, n / 2);
            }
            else{
                return x * myPow(x * x, n / 2 - 1);
            }
        }
        
    }
};
