lc302-1.cpp

//brute force
class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int lowX = x;
        int highX = x;
        int lowY = y;
        int highY = y;
        for(int i = 0; i < image.size(); i++){
            for(int j = 0; j < image[0].size(); j++){
                if(image[i][j] == '1'){
                    lowX = min(lowX, i);
                    highX = max(highX, i);
                    lowY = min(lowY, j);
                    highY = max(highY,j);
                }
            }
        }
        return (highX - lowX + 1) * (highY - lowY + 1);
    }
};
