//c++里面include的时候，只能写全，不能通配
//能不用就不要用++i 这种方式
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        if(s.empty()) return true;
        for(int i = 0; i < n; i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }
            if(s[i] == ')'){
                if(st.empty() || st.top() != '('){
                    return false;
                }
                    st.pop();
            }
            if(s[i] == ']'){
                if(st.empty() || st.top() != '['){
                    return false;
                }
                    st.pop();
            }
            if(s[i] == '}'){
                if(st.empty() || st.top() != '{'){
                    return false;
                }
                    st.pop();
            }
        }
        return st.empty();
    }
};
