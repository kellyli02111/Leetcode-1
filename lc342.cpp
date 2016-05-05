class Solution {
public:
    bool isPowerOfFour(int num) {
        int max1 = 1431655765; //0b1010101010101010101010101010101
        int max2 = (1 << 30);
        return ((num > 0) && (max2 % num == 0) && ((max1 | num) == max1));
    }
};
