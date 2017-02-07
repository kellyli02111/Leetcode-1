class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res(A.size(), vector<int>(B[0].size(), 0));
        int m = A.size();
        int n = A[0].size();
        int p = B[0].size();
        vector<pair<int, int>> v1;
        unordered_map<int, vector<int>> um1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(A[i][j] != 0){
                    v1.push_back(make_pair(i, j));
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < p; j++){
                if(B[i][j] != 0){
                    um1[i].push_back(j);
                }
            }
        }
        
        for(int i = 0; i < v1.size(); i++){
            int x1 = v1[i].first;
            int y1 = v1[i].second;
            int val1 = A[x1][y1];
            int x2 = y1;
            vector<int> v2 = um1[x2];
            for(int j = 0; j < v2.size(); j++){
                int y2 = v2[j];
                int val2 = B[x2][y2];
                res[x1][y2] = res[x1][y2] + val1 * val2;
            }
        }
        return res;
    }
};
