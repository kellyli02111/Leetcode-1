class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return findStrobogrammatic_sub(n, n);
    }
    
    vector<string> findStrobogrammatic_sub(int n, int size) {
        vector<string> res;
        if(n == 0){
            res.push_back("");
            return res;
        }
        if(n == 1){
            res.push_back("0");
            res.push_back("1");
            res.push_back("8");
            return res;
        }
        vector<string> res_last = findStrobogrammatic_sub(n - 2, size);
        if(n == size){
            for(int i = 0; i < res_last.size(); i++){
                res.push_back("1" + res_last[i] + "1");
                res.push_back("6" + res_last[i] + "9");
                res.push_back("8" + res_last[i] + "8");
                res.push_back("9" + res_last[i] + "6");
            }
        }
        else{
            for(int i = 0; i < res_last.size(); i++){
                res.push_back("0" + res_last[i] + "0");
                res.push_back("1" + res_last[i] + "1");
                res.push_back("6" + res_last[i] + "9");
                res.push_back("8" + res_last[i] + "8");
                res.push_back("9" + res_last[i] + "6");
            }
        }
        return res;
    }
};
