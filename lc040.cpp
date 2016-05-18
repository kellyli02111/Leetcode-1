class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int sum = 0;
        vector<int> solution;
        vector<vector<int>> result;
        combination(candidates, target, sum, 0, solution, result);
        return result;
    }
    
    void combination(vector<int>& candidates, int target, int& sum, int level, vector<int>& solution, vector<vector<int>>& result){
        if(sum > target) return;
        if(sum == target){
            result.push_back(solution);
            return;
        }
        for(int i = level; i < candidates.size(); i++){
            solution.push_back(candidates[i]);
            sum = sum + candidates[i];
            combination(candidates, target, sum, i + 1, solution, result);
            sum = sum - candidates[i];
            solution.pop_back();
            while((i < candidates.size() - 1) && (candidates[i] == candidates[i + 1])) i++;
        }
    }
};
