//binary search
class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size();
        int n = image[0].size();
        int low = 0;
        int high = x;
        while(low < high){
            int mid = (low + high) / 2;
            if(searchRow(image, mid)){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        int minX = low;
        low = x;
        high = m;
        while(low < high){
            int mid = (low + high) / 2;
            if(searchRow(image, mid)){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        int maxX = low - 1;
        low = 0;
        high = y;
        while(low < high){
            int mid = (low + high) / 2;
            if(searchCol(image, mid)){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        int minY = low;
        low = y;
        high = n;
        while(low < high){
            int mid = (low + high) / 2;
            if(searchCol(image, mid)){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        int maxY = low - 1;
        
        return (maxX - minX + 1) * (maxY - minY + 1);
    }
    
    bool searchRow(vector<vector<char>>& image, int x){
        for(int j = 0; j < image[0].size(); j++){
            if(image[x][j] == '1') return true;
        }
        return false;
    }
    
    bool searchCol(vector<vector<char>>& image, int y){
        for(int i = 0; i < image.size(); i++){
            if(image[i][y] == '1') return true;
        }
        return false;
    }
};
