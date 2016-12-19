class Vector2D {
private: 
vector<vector<int>> v;
int x;
int y;
    
public:
    Vector2D(vector<vector<int>>& vec2d) {
        v = vec2d;
        x = 0;
        y = 0;
    }

    int next() {
        return v[x][y++];
    }

    bool hasNext() {
        while(x < v.size() && y == v[x].size()){
            x++;
            y = 0;
        }
        return x < v.size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
