class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";
        string res;
        if(numerator < 0 ^ denominator < 0){
            res = res + '-';
        }
        //转化为正数，INT_MIN转化为正数会溢出，故用long long。long long int n=abs(INT_MIN)得到的n仍然是负的，所以写成下面的形式。
        long long n = numerator;
        long long d = denominator;
        n = abs(n);
        d = abs(d);
        res = res + to_string(n / d);
        long long r = n % d;
        if(r == 0) return res;
        else{
            res = res + '.';
        }
        unordered_map<long long, int> map;
        while(r != 0){
            if(map.find(r) != map.end()){
                res.insert(map[r], "(");
                res = res + ')';
                break;
            }
            map[r] = res.size();
            r = r * 10;
            res = res + to_string(r / d);
            r = r % d;
        }
        return res;
    }
};
