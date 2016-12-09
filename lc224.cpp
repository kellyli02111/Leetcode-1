class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        if(n == 0) return 0;
        stack<int> stk;
        int res = 0;
        int num = 0;
        int sign = 1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' ') continue;
            if(s[i] >= '0' && s[i] <= '9'){
                num = num * 10 + (s[i] - '0');
                continue;
            }
            if(s[i] == '+'){
                res = res + sign * num;
                sign = 1;
                num = 0;
                continue;
            }
            if(s[i] == '-'){
                res = res + sign * num;
                sign = -1;
                num = 0;
                continue;
            }
            if(s[i] == '('){
                stk.push(res);
                stk.push(sign);
                res = 0;
                num = 0;
                sign = 1;
            }
            if(s[i] == ')'){
                res = res + sign * num;
                sign = stk.top();
                stk.pop();
                res = stk.top() + sign * res;
                stk.pop();
                num = 0;
            }
        }
        res = res + sign * num;
        return res;
    }
};
