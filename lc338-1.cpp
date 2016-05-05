class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        res.push_back(0);
        if(num == 0) return res;
        int len = 1;
        while(true){
            for(int i = 0; i < len; i++){
                if(len + i > num) return res;
                res.push_back(res[i] + 1);
            }
            len = len * 2;
        }
    }
};
