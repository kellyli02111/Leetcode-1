class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            unordered_set<int> s;
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                int temp = board[i][j] - '0';
                if(temp < 1 || temp > 9) return false;
                else{
                    if(s.find(temp) != s.end()){
                        return false;
                    }
                    s.insert(temp);
                }
            }
        }
        for(int i = 0; i < 9; i++){
            unordered_set<int> s;
            for(int j = 0; j < 9; j++){
                if(board[j][i] == '.') continue;
                int temp = board[j][i] - '0';
                if(temp < 1 || temp > 9) continue;
                else{
                    if(s.find(temp) != s.end()){
                        return false;
                    }
                    s.insert(temp);
                }
            }
        }
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                unordered_set<int> s;
                for(int m = 0; m < 3; m++){
                    for(int n = 0; n < 3; n++){
                        if(board[3 * i + m][3 * j + n] == '.') continue;
                        int temp = board[3 * i + m][3 * j + n] - '0';
                        if(temp < 1 || temp > 9) return false;
                        else{
                            if(s.find(temp) != s.end()){
                                return false;
                            }
                            s.insert(temp);
                        }
                    }
                }
            }
        }
        return true;
    }
};
