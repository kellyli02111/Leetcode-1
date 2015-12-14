class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 2) return 0;
        int res = 0;
        int leftInd = 0;
        int leftVal = height[leftInd];
        int rightInd = n - 1;
        int rightVal = height[rightInd];
        while(leftInd < rightInd){
            while(leftInd < rightInd && leftVal <= height[leftInd + 1]){
                leftInd++;
                leftVal = height[leftInd];
            }
            while(rightInd > leftInd && rightVal <= height[rightInd - 1]){
                rightInd--;
                rightVal = height[rightInd];
            }
            if(leftInd >= rightInd) break;
            if(leftVal < rightVal){
                leftInd++;
                res = res + (leftVal - height[leftInd]);
            }
            else{
                rightInd--;
                res = res + (rightVal - height[rightInd]);
            }
        }
        return res;
    }
};
