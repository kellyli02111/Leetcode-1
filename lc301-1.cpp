//dfs
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        vector<char> par = {'(', ')'};
        dfs(s, res, 0, 0, par);
        return res;
    }
    
    void dfs(string s, vector<string>& res, int last_i, int last_j, vector<char> par){
        int count = 0;
        for(int i = last_i; i < s.size(); i++){
            if(s[i] == par[0]) count++;
            if(s[i] == par[1]) count--;
            if(count >= 0) continue;
            for(int j = last_j; j <= i; j++){
                if(s[j] == par[1] && (j == last_j || s[j - 1] != par[1])){
                    dfs(s.substr(0, j) + s.substr(j + 1), res, i, j, par);
                }
            }
            return;
        }
        reverse(s.begin(), s.end());
        if(par[0] == '('){
            par = {')', '('};
            dfs(s, res, 0, 0, par);
        }
        else{
            res.push_back(s);
        }
    }
};
