class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        if(n < 3) return false;
        for(int i = 1; i < n; i++){
            for(int j = i + 1; j < n; j++){
                string s1 = num.substr(0, i);
                string s2 = num.substr(i, j - i);
                if((s1.size() > 1 && s1[0] == '0') || (s2.size() > 1 && s2[0] == '0')) continue;
                int curLen = j;
                string s3 = strAdd(s1, s2);
                int nextLen = s3.size();
                if(curLen + nextLen > n) continue;
                if(num.substr(curLen, nextLen) != s3) continue;
                if(curLen + nextLen == n) return true;
                while(true){
                    curLen = curLen + nextLen;
                    s1 = s2;
                    s2 = s3;
                    s3 = strAdd(s1, s2);
                    nextLen = s3.size();
                    if(curLen + nextLen > n) break;
                    if(num.substr(curLen, nextLen) != s3) break;
                    if(curLen + nextLen == n) return true;
                }
            }
        }
        return false;
    }
    
    string strAdd(string num1, string num2){
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int k = max(num1.size(), num2.size());
        string res(k + 1, '0');
        int tmp = 0;
        while(i >= 0 || j >= 0 || tmp){
            if(i >= 0){
                tmp = tmp + (num1[i] - '0');
            }
            if(j >= 0){
                tmp = tmp + (num2[j] - '0');
            }
            res[k] = (tmp % 10) + '0';
            tmp = tmp / 10;
            i--;
            j--;
            k--;
        }
        
        if(res.size() > 1 && res[0] == '0'){
            res.erase(res.begin());
        }
        return res;
    }
};
