class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        int res = 0;
        find(low, high, "", res);
        find(low, high, "0", res);
        find(low, high, "1", res);
        find(low, high, "8", res);
        return res;
    }
    
    void find(string low, string high, string path, int& res){
        int pSize = path.size();
        if(pSize >= low.size() && pSize <= high.size()){
            if((pSize == low.size() && path.compare(low) < 0) || (pSize == high.size() && path.compare(high) > 0)){
                return;
            }
            if(!(pSize > 1 && path[0] == '0')){
                res++;
            }
        }
        if(pSize + 2 > high.size()) return;
        find(low, high, "0" + path + "0", res);
        find(low, high, "1" + path + "1", res);
        find(low, high, "6" + path + "9", res);
        find(low, high, "8" + path + "8", res);
        find(low, high, "9" + path + "6", res);
    }
};
