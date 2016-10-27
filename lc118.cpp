class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows == 0) return res;
        vector<int> curRow;
        curRow.push_back(1);
        res.push_back(curRow);
        curRow.clear();
        for(int i =1; i < numRows; i++){
            curRow.push_back(1);
            for(int j = 1; j < i; j++){
                curRow.push_back(res[i - 1][j-1] + res[i - 1][j]);
            }
            curRow.push_back(1);
            res.push_back(curRow);
            curRow.clear();
        }
        return res;
    }
};
