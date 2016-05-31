class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int row;
        bool flag = false;
        int start = 0;
        int end = m - 1;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(matrix[mid][0] == target) return true;
            else if(matrix[mid][0] > target){
                end = mid - 1;
            }
            else{
                if(mid + 1 >= m || matrix[mid + 1][0] > target){
                    row = mid;
                    flag = true;
                    break;
                }
                else{
                    start = mid + 1;
                }
            }
        }
        if(!flag){
            row = start;
        }
        start = 0;
        end = n - 1;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(matrix[row][mid] == target) return true;
            else if(matrix[row][mid] > target){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return false;
    }
};
