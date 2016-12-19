class Vector2D {
private: 
vector<int> v;
int loc = 0;
    
public:
    Vector2D(vector<vector<int>>& vec2d) {
        for(int i = 0; i < vec2d.size(); i++){
            for(int j = 0; j < vec2d[i].size(); j++){
                v.push_back(vec2d[i][j]);
            }
        }
    }

    int next() {
        return v[loc++];
    }

    bool hasNext() {
        return (loc < v.size());
        cout<<"here"<<endl;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
