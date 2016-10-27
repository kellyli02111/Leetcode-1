class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> curRow;
        vector<int> preRow;
        curRow.push_back(1);
        if(rowIndex == 0) return curRow;
        for(int i = 0; i < rowIndex; i++){
            preRow = curRow;
            curRow.clear();
            curRow.push_back(1);
            for(int j = 0; j < i; j++){
                curRow.push_back(preRow[j] + preRow[j + 1]);
            }
            curRow.push_back(1);
        }
        return curRow;
    }
};
