class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fac(n, 0);
        fac[0] = 1;
        for(int i = 1; i < n; i++){
            fac[i] = fac[i - 1] * i;
        }
        vector<int> nums;
        for(int i = 1; i <= n; i++){
            nums.push_back(i);
        }
        string res = "";
        for(int i = n - 1; i>= 0; i--){
            int temp = (k - 1) / fac[i];
            res.push_back('0' + nums[temp]);
            nums.erase(nums.begin() + temp);
            k = k - temp * fac[i];
        }
        return res;
    }
};
