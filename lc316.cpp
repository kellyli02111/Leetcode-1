class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> m(256, 0);
        vector<int> visited(256, 0);
        string res = "";
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            m[c]++;
        }
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            m[c]--;
            if(visited[c]) continue;
            while(res.size() > 0 && c < res.back() && m[res.back()] > 0){
                visited[res.back()] = 0;
                res.pop_back();
            }
            res.push_back(c);
            visited[c] = 1;
        }
        return res;
    }
};
