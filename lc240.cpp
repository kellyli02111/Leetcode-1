class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int j = matrix[0].size() - 1;
        for(int i = 0; i < matrix.size(); i++){
            if(j < 0) return false;
            if(matrix[i][j] == target) return true;
            while(matrix[i][j] > target){
                j--;
                if(j < 0) return false;
                if(matrix[i][j] == target) return true;
            } 
        }
        return false;
    }
};
