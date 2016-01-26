class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int res = 0;
        if(matrix.empty() || matrix[0].empty()){
            return res;
        }
        vector<int> heights(matrix[0].size(), 0);
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == '0'){
                    heights[j] = 0;
                }
                else{
                    heights[j]++;
                }
            }
            res = max(res, largestRectangleArea(heights));
        }
        return res;
    }
    
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
        heights.pop_back();
        heights.erase(heights.begin());
        return res;
    }
};
