//DFS causes stack overflow, not an error and reported as runtime error
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty()) return;
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < board.size(); i++){
            dfs(board, i, 0);
            dfs(board, i, n - 1);
        }
        for(int j = 0; j < board[0].size(); j++){
            dfs(board, 0, j);
            dfs(board, m - 1, j);
        }
        for(int i = 0; i < m; i++){
            for(int j = 0 ; j < n; j++){
                if(board[i][j] == 'V'){
                    board[i][j] = 'O';
                }
                else{
                    board[i][j] = 'X';
                }
            }
        }
    }
    void dfs(vector<vector<char>>& board, int row, int col){
        int numRow = board.size();
        int numCol = board[0].size();
        if(row < 0 || col < 0 || row >= numRow || col >= numCol) return;
        if(board[row][col] != 'O') return;
        board[row][col]= 'V';
        dfs(board, row - 1, col);
        dfs(board, row + 1, col);
        dfs(board, row, col - 1);
        dfs(board, row, col + 1);
        
    }
};
