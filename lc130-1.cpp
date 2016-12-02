class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty()) return;
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < board.size(); i++){
            bfs(board, i, 0);
            bfs(board, i, n - 1);
        }
        for(int j = 0; j < board[0].size(); j++){
            bfs(board, 0, j);
            bfs(board, m - 1, j);
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
    
    void bfs(vector<vector<char>>& board, int row, int col){
        if(board[row][col] != 'O') return;
        int numRow = board.size();
        int numCol = board[0].size();
        queue<pair<int, int>> q;
        q.push(make_pair(row, col));
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(i < 0 || j < 0 || i >= numRow || j >= numCol) continue;
            if(board[i][j] != 'O') continue;
            board[i][j] = 'V';
            q.push(make_pair(i - 1, j));
            q.push(make_pair(i + 1, j));
            q.push(make_pair(i, j - 1));
            q.push(make_pair(i, j + 1));
        }
    }
};
