class Solution {
public:
    int countPrimes(int n) {
        int res = 1;
        vector<bool> sieve(n, false);
        for(int i = 2; i * i < n; i++){
            for(int j = 2 * i; j < n; j = j + i){
                sieve[j - 1] = true;
            }
        }
        for(int i = 1; i < n - 1; i++){
            if(!sieve[i]) res++;
        }
        return (res - 1);
    }
};
