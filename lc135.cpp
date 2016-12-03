//从左到右，递增的话+1，否则都给一块糖，再从右往左，遇到递增不符合，调整
class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.empty()) return 0;
        int res = 0;
        int n = ratings.size();
        vector<int> numCandy(n, 1);
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i - 1]){
                numCandy[i] = numCandy[i - 1] + 1;
            }
        }
        for(int i = n - 2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1] && numCandy[i] <= numCandy[i + 1]){
                numCandy[i] = numCandy[i + 1] + 1;
            }
        }
        for(int i = 0; i < n; i++){
            res = res + numCandy[i];
        }
        return res;
    }
};
