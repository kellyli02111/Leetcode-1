class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(res, cur, n, 2);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, vector<int>& cur, int num, int den){
        for(int i = den; i * i <= num; i++){
            if(num % i == 0){
                vector<int> newCur = cur;
                newCur.push_back(i);
                dfs(res, newCur, num / i, i);
                newCur.push_back(num / i);
                res.push_back(newCur);
            }
        }
        return;
    }
};
