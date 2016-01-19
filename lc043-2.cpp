class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1[0] == '0' || num2[0] == '0') return "0";
        
        string res = "";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int carry = 0;
        int len = 0;
        int n1 = num1.size();
        int n2 = num2.size();
        while(true){
            bool flag = false;
            int temp = 0;
            for(int i = 0; i < n1; i++){
                int j = len - i;
                if(j < 0 || j >= n2) continue;
                temp = temp + (num1[i] - '0') * (num2[j] - '0');
                flag = true;
            }
            if(flag == false) break;
            temp = temp + carry;
            carry = temp / 10;
            temp = temp % 10;
            res.push_back('0' + temp);
            len++;
        }
        while(carry != 0){
            res.push_back('0' + carry % 10);
            carry = carry / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
