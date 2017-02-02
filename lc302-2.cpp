lc302-2.cpp

//dfs
class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int lowX = x;
        int highX = x;
        int lowY = y;
        int highY = y;
        dfs(image, x, y, lowX, highX, lowY, highY);
        return (highX - lowX + 1) * (highY - lowY + 1);
    }
    
    void dfs(vector<vector<char>>& image, int x, int y, int& lowX, int& highX, int& lowY, int& highY){
        if(x < 0 || x >= image.size() || y < 0 || y >= image[0].size() || image[x][y] != '1') return;
        lowX = min(lowX, x);
        highX = max(highX, x);
        lowY = min(lowY, y);
        highY = max(highY, y);
        image[x][y] = '2';
        dfs(image, x - 1, y, lowX, highX, lowY, highY);
        dfs(image, x + 1, y, lowX, highX, lowY, highY);
        dfs(image, x, y - 1, lowX, highX, lowY, highY);
        dfs(image, x, y + 1, lowX, highX, lowY, highY);
    }
};
