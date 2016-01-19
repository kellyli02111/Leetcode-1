class Solution {
public:
    bool isValid(vector<int>& state, int x, int y){
        for(int i = 0; i < x; i++){
            if(state[i] == y || (i + state[i] == x + y) || (i - state[i] == x - y)){
                return false;
            }
        }
        return true;
    }
    
    void solveNQueens_sub(int& res, vector<int>& state, int x){
        if(x == state.size()){
            res++;
            return;
        }
        for(int j = 0; j < state.size(); j++){
            state[x] = j;
            if(isValid(state, x, j)){
                solveNQueens_sub(res, state, x + 1);
            }
            state[x] = -1;
        }
    }
    
    int totalNQueens(int n) {
        int res = 0;
        vector<int> state(n, -1);
        solveNQueens_sub(res, state, 0);
        return res;
    }
};
