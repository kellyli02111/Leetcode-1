class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        if(n == 0) return 0;
        int res = 0;
        int num = 0;
        int lastNum = 0;
        int sign = 1;
        int op = 0; //0 for + or -, 1 for *, 2 for /
        for(int i = 0; i < n; i++){
            if(s[i] == ' ') continue;
            if(s[i] >= '0' && s[i] <= '9'){
                num = 0;
            }
            while(s[i] >= '0' && s[i] <= '9'){
                num = 10 * num + (s[i] - '0');
                i++;
            }
            if(op == 0){
                lastNum = num;
            }
            else if(op == 1){
                lastNum = lastNum * num;
                num = 0;
            }
            else if(op == 2){
                lastNum = lastNum / num;
                num = 0;
            }
            
            if(s[i] == '+'){
                res = res + sign * lastNum;
                num = 0;
                sign = 1;
                op = 0;
            }
            if(s[i] == '-'){
                res = res + sign * lastNum;
                sign = -1;
                op = 0;
            }
            if(s[i] == '*'){
                op = 1;
            }
            if(s[i] == '/'){
                op = 2;
            }
        }
        res = res + sign * lastNum;
        return res;
    }
};
