//取两边板为初始面积，从短板一边看过去其他所有板可以排除，只需要将短板往里移，每次循环如上：
class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.empty()) return 0;
        int n = height.size();
        int start = 0;
        int end = n-1;
        int res = (n-1) * min(height[0], height[n-1]);
        while(start != end){
            if(height[start] <= height[end]){
                start++;
            }
            else{
                end--;
            }
            int areaNew = (end - start) * min(height[end], height[start]);
            if(areaNew > res){
                res = areaNew;
            }
        }
        return res;
    }
};
