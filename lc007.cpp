class Solution {
public:
    int reverse(int x) {
        long long temp = x;
        long long res = 0;
        while(temp != 0){
            res = res * 10;
            res = res + (temp % 10);
            temp = temp / 10;
        }
        if(res > INT_MAX || res < INT_MIN) return 0;
        return res;
    }
};
