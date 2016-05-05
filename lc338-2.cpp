class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res = {0};
        int flag = 2;
        for(int i = 1; i <= num; i++){
            if(i >= flag) flag = flag * 2;
            res.push_back(res[i - flag / 2] + 1);
        }
        return res;
    }
};
