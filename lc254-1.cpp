class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(res, cur, n, 2);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, vector<int>& cur, int num, int den){
        if(num == 1 && cur.size() > 1){
            res.push_back(cur);
        }
        else{
            for(int i = den; i <= num; i++){
                if(num % i == 0){
                    cur.push_back(i);
                    dfs(res, cur, num / i, i);
                }
            }
        }
        cur.pop_back();
        return;
    }
};
