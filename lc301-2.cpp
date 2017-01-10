//bfs
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        queue<string> q;
        unordered_set<string> us;
        q.push(s);
        us.insert(s);
        bool found = false;
        while(!q.empty()){
            string cur = q.front();
            q.pop();
            if(isValid(cur)){
                res.push_back(cur);
                found = true;
            }
            if(found) continue; //非常重要，保证只移除最少的括号
            for(int i = 0; i < cur.size(); i++){
                if(cur[i] != '(' && cur[i] != ')') continue;
                string newStr = cur.substr(0, i) + cur.substr(i + 1);
                if(us.find(newStr) == us.end()){
                    q.push(newStr);
                    us.insert(newStr);
                }
            }
        }
        return res;
    }
    
    bool isValid(string s){
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                count++;
            }
            else if(s[i] == ')'){
                if(count > 0){
                    count--;
                }
                else{
                    return false;
                }
            }
        }
        return (count == 0);
    }
};
