class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        dfs(num, target, 0, 0, "", res);
        return res;
    }
    
    void dfs(string num, int target, long long prev, long long curRes, string out, vector<string>& res){
        if(num.size() == 0 && curRes == target){
            res.push_back(out);
        }
        for(int i = 1; i <= num.size(); i++){
            string cur = num.substr(0, i);
            if(cur.size() > 1 && cur[0] == '0') return;
            string next = num.substr(i);
            
            if(out.size() > 0){
                dfs(next, target, stoll(cur), curRes + stoll(cur), out + "+" + cur, res);
                dfs(next, target, -stoll(cur), curRes - stoll(cur), out + "-" + cur, res);
                dfs(next, target, prev * stoll(cur), (curRes - prev) + prev * stoll(cur), out + "*" + cur, res);
            }
            else{
                dfs(next, target, stoll(cur), curRes + stoll(cur), cur, res);
            }
        }
    }
};
