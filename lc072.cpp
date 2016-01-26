//Wagner–Fischer algorithm
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>>matrix(word1.size() + 1, vector<int>(word2.size() + 1, INT_MAX));
        for(int i = 0; i <= word1.size(); i++){
            matrix[i][0] = i;
        }
        for(int j = 0; j <= word2.size(); j++){
            matrix[0][j] = j;
        }
        for(int i = 1; i <= word1.size(); i++){
            for(int j = 1; j <= word2.size(); j++){
                if(word1[i - 1] == word2[j - 1]){
                    matrix[i][j] = matrix[i - 1][j - 1];
                }
                else{
                    matrix[i][j] = min(matrix[i][j], matrix[i - 1][j] + 1);
                    matrix[i][j] = min(matrix[i][j], matrix[i][j - 1] + 1);
                    matrix[i][j] = min(matrix[i][j], matrix[i - 1][j - 1] + 1);
                }
            }
        }
        return matrix[word1.size()][word2.size()];
    }
};
