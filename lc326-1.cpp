class Solution {
public:
    bool isPowerOfThree(int n) {
        int iter = (int)(log10(n) / log10(3)); //不能用log()会有rounding error
        int num = 1;
        for(int i = 0; i < iter; i++){
            num = num * 3;
        }
        return num == n;
    }
};
