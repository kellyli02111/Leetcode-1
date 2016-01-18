class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int N = 9;
        int col[N];
        int box[N];
        memset(col, 0, sizeof(col));
        memset(box, 0, sizeof(box));
        for(int i = 0; i < 9; i++){
            int row = 0;
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                if(board[i][j] < '1' || board[i][j] > '9'){
                    return false;
                }
                int temp = 1 << (board[i][j] - '1');
                int boxIndex = i / 3 * 3 + j / 3;
                if((row & temp) || (col[j] & temp) || (box[boxIndex] & temp)){
                    return false;
                }
                row = row | temp;
                col[j] = col[j] | temp;
                box[boxIndex] = box[boxIndex] | temp;
            }
        }
        return true;
    }
};
