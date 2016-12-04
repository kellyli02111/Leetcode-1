class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while(n > 0){
            int r = n % 26;
            if(r != 0){
                res = char('A' + r - 1) + res;
                n = n / 26;
            }
            else{
                res = 'Z' + res;
                n = n / 26;
                n--;
            }
        }
        return res;
    }
};
