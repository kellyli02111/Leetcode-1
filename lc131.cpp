class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> cur;
        dfs(s, res, cur, 0);
        return res;
    }
    void dfs(string& s, vector<vector<string>>& res, vector<string>& cur, int start){
        if(start == s.size()){
            res.push_back(cur);
            return;
        }
        for(int i = start; i < s.size(); i++){
            if(isPalindrome(s, start, i)){
                cur.push_back(s.substr(start, i - start + 1));
                dfs(s, res, cur, i + 1);
                cur.pop_back();
            }
        }
    }
    
    bool isPalindrome(string& s, int start, int end){
        while(start < end){
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        cout<<s.substr(start, end - start + 1)<<endl;
        return true;
    }
};
