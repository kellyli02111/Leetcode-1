class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(res, cur, k, 1, n);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, vector<int>& cur, int k, int minVal, int left){
        if(cur.size() == k && left == 0){
            res.push_back(cur);
            return;
        }
        if(left < 0 || cur.size() > k) return;
        if(cur.size() == k && left != 0) return;
        for(int i = minVal; i <= 9; i++){
            cur.push_back(i);
            dfs(res, cur, k, i + 1, left - i);
            cur.pop_back();
        }
    }
};
