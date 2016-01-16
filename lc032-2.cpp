class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        stack<int> st;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if((s[i] == ')') && (!st.empty()) && (s[st.top()] == '(')){
                int tempLen;
                st.pop();
                if(st.empty()){
                    tempLen = i + 1;
                }
                else{
                    tempLen = i - st.top();
                }
                res = max(res, tempLen);
            }
            else{
                st.push(i);
            }
        }
        return res;
    }
};
