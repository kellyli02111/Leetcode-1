//State machine
//http://www.cnblogs.com/grandyang/p/4854466.html
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.size() == 0 || board[0].size() == 0) return;
        int m = board.size();
        int n = board[0].size();
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int count = 0;
                for(int k = 0; k < 8; k++){
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(x >= 0 && x < m && y >= 0 && y < n && (board[x][y] == 1 || board[x][y] == 2)){
                        count++;
                    }
                }
                if(board[i][j] == 0 && count == 3){
                    board[i][j] = 3;
                    continue;
                }
                if(board[i][j] == 1 && (count < 2 || count > 3)){
                    board[i][j] = 2;
                    continue;
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                board[i][j] = board[i][j] % 2;
            }
        }
    }
};
