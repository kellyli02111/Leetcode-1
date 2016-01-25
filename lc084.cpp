class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int res = 0;
        if(heights.empty()) return res;
        heights.push_back(0);
        heights.insert(heights.begin(), 0);
        for(int i = 0; i < heights.size(); i++){
            while(!s.empty() && heights[i] < heights[s.top()]){
                int h = heights[s.top()];
                s.pop();
                res = max(res, (i - s.top() - 1) * h);
            }
            s.push(i);
        }
        return res;
    }
};
