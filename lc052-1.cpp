class Solution {
public:
    bool isValid(vector<string>& board, int x, int y){
        int nsize = board.size();
        for(int i = 0; i < nsize; i++){
            if(i != x && board[i][y] == 'Q'){
                return false;
            }
        }
        for(int j = 0; j < nsize; j++){
            if(j != y && board[x][j] == 'Q'){
                return false;
            }
        }
        for(int i = 0; i < nsize; i++){
            int j = x + y - i;
            if(j >= 0 && j <= nsize && i != x && board[i][j] == 'Q'){
                return false;
            }
        }
        for(int i = 0; i < nsize; i++){
            int j = i - x + y;
            if(j >= 0 && j <= nsize && i != x && board[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
    
    void solveNQueens_sub(int& res, vector<string>& board, int x){
        if(x == board.size()){
            res++;
            return;
        }
        for(int j = 0; j < board.size(); j++){
            board[x][j] = 'Q';
            if(isValid(board, x, j)){
                solveNQueens_sub(res, board, x + 1);
            }
            board[x][j] = '.';
        }
    }
    
    int totalNQueens(int n) {
        int res = 0;
        string row(n, '.');
        vector<string> board(n, row);
        solveNQueens_sub(res, board, 0);
        return res;
    }
};
