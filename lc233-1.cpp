class Solution {
public:
    int countDigitOne(int n) {
        if(n < 1) return 0;
        vector<int> vec;
        vec.push_back(0);
        vec.push_back(1);
        int temp = 10;
        for(int i = 2; temp < n; i++){
            vec.push_back(10 * vec[i - 1] + temp);
            temp = temp * 10;
        }
        int ind = 0;
        int base = 1;
        int res = 0;
        while(n / base >= 10){
            ind++;
            base = base * 10;
        }
        while(ind >= 0){
            if(n / base > 1){
                res = res + (n / base) * vec[ind] + base;
                
            }
            else if (n / base == 1){
                res = res + vec[ind] + (n % base + 1);
            }
            n = n % base;
            ind--;
            base = base / 10;
        }
        return res;
    }
};
