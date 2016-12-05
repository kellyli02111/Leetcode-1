class Solution {
public:
    bool isHappy(int n) {
        if(n == 1) return true;
        unordered_set<int> us;
        while(us.find(n) == us.end()){
            
            if(n == 1) return true;
            us.insert(n);
            n = digitSqSum(n);
        }
        return false;
    }
    
    int digitSqSum(int n){
        int res = 0;
        while(n != 0){
            int rmn = n % 10;
            res = res + rmn * rmn;
            n = n / 10;
        }
        return res;
    }
};
