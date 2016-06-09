class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        if(n == 0){
            res.push_back(0);
            return res;
        }
        if(n == 1){
            res.push_back(0);
            res.push_back(1);
            return res;
        }
        res.push_back(0);
        res.push_back(1);
        for(int i = 2; i < (1<<n); i++){
            res.push_back(i ^ (i >> 1));
        }
        return res;
    }
};
