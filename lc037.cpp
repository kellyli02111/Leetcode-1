class Solution {
public:
    bool isValid(vector<vector<char>>& board, int x, int y){
        if(board[x][y] == '.'){
            return true;
        }
        if(board[x][y] < '1' || board[x][y] > '9'){
            return false;
        }
        for(int j = 0; j < 9; j++){
            if(y != j && board[x][y] == board[x][j]){
                return false;
            }
        }
        for(int i = 0; i < 9; i++){
            if(x != i && board[x][y] == board[i][y]){
                return false;
            }
        }
        for(int i = x / 3 * 3; i < x / 3 * 3 + 3; i++){
            for(int j = y / 3 * 3; j < y / 3 * 3 + 3; j++){
                if((x != i || y != j) && board[x][y] == board[i][j]){
                    return false;
                }
            }
        }
        return true;
    }

    bool solveSudoku_sub(vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.') continue;
                for(int k = 0; k < 9; k++){
                    board[i][j] = k + '1';
                    if(isValid(board, i, j)){
                        if(solveSudoku_sub(board)){
                            return true;
                        }
                    }
                }
                board[i][j] = '.';
                return false;
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solveSudoku_sub(board);
        return;
    }
};
