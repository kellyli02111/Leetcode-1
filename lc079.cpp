class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size() == 0) return true;
        int len = word.size();
        int m = board.size();
        if(m == 0) return false;
        int n = board[0].size();
        if(n == 0) return false;
        vector<vector<bool>> flag(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(search(board, word, flag, i, j, 0)) return true;
            }
        }
        return false;
    }
    
    bool search(vector<vector<char>>& board, string& word, vector<vector<bool>>& flag, int i, int j, int idx){
        if(idx == word.size()) return true;
        if(i < 0 || i >= board.size()) return false;
        if(j < 0 || j >= board[0].size()) return false;
        if(flag[i][j]) return false;
        if(board[i][j] != word[idx]) return false;
        flag[i][j] = true;
        if(search(board, word, flag, i + 1, j, idx + 1) == true) return true;
        if(search(board, word, flag, i - 1, j, idx + 1) == true) return true;
        if(search(board, word, flag, i, j + 1, idx + 1) == true) return true;
        if(search(board, word, flag, i, j - 1, idx + 1) == true) return true;
        flag[i][j] = false;
        return false;
    }
};
