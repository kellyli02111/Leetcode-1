class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> solution;
        vector<vector<int>> res;
        getCombine(n, k, 1, solution, res);
        return res;
    }
    
    void getCombine(int n, int k, int lvl, vector<int>& solution, vector<vector<int>>& res){
        if(solution.size() == k){
            res.push_back(solution);
            return;
        }
        for(int i = lvl; i <= n; i++){
            solution.push_back(i);
            getCombine(n, k, i + 1, solution, res);
            solution.pop_back();
        }
    }
};
