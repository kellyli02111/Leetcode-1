class Solution {
public:
    int numTrees(int n) {
        vector<int> res;
        res.push_back(1);
        for(int i = 2; i <= n; i++){
            int temp = 0;
            for(int j = 1; j <= i; j++){
                int leftDist = j - 1;
                int rightDist = i - j;
                if(leftDist == 0) leftDist = 1;
                if(rightDist == 0) rightDist = 1;
                temp = temp + res[leftDist - 1] * res[rightDist - 1];
            }
            res.push_back(temp);
        }
        return res[n - 1];
    }
};
