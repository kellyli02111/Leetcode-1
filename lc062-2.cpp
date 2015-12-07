//同一个class不需要事先声明空的method，放在后面没有关系。
//二维数组对一维数组的引用是新作一份copy，之后更改一维数组不会对二维数组造成影响。
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> matrixNew(m, vector<int>(n, 1));
        for(int i = 1; i<m; i++){
            for(int j = 1; j<n; j++){
                matrixNew[i][j] = matrixNew[i-1][j] + matrixNew[i][j-1];
            }
        }
        return matrixNew[m-1][n-1];
    }
};
//矩阵：时间O(n^2), 空间O(n^2)
