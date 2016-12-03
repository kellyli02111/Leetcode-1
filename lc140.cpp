//DP + 剪枝
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        string cur;
        vector<string> res;
        int len = s.size();
        vector<bool> dp(len + 1, true);
        GenSolution(s, res, cur, wordDict, 0, len, dp);
        return res;
    }
    
    void GenSolution(string& s, vector<string>& res, string cur, unordered_set<string>& wordDict, int start, int len, vector<bool>& dp){
        if(start == len){
            cur = cur.substr(0, cur.size() - 1);
            res.push_back(cur);
            return;
        }
        for(int i = start; i < len; i++){
            string piece = s.substr(start, i - start + 1);
            if(wordDict.find(piece) != wordDict.end() && dp[i + 1]){
                int beforeAppendSize = res.size();
                cur.append(piece).append(" ");
                GenSolution(s, res, cur, wordDict, i + 1, len, dp);
                if(res.size() == beforeAppendSize){
                    dp[i + 1] = false;
                }
                cur = cur.substr(0, cur.size() - piece.size() - 1);
            }
        }
    }
};
