class Solution {
public:
    string addBinary(string a, string b) {
        int aLen = a.size();
        int bLen = b.size();
        int aIndex = aLen - 1;
        int bIndex = bLen - 1;
        int carry = 0;
        string res = "";
        while(aIndex >= 0 || bIndex >= 0 || carry != 0){
            int cInt = 0;
            if (aIndex >=0){
                int aInt = a[aIndex] - '0';
                cInt = cInt + aInt;
            }
            if(bIndex >= 0){
                int bInt = b[bIndex] - '0';
                cInt = cInt + bInt;
            }
            cInt = cInt + carry;
            carry = cInt / 2;
            cInt = cInt % 2;
            res = (char)(cInt + '0') + res;
            aIndex--;
            bIndex--;
            continue;
        }
        return res;
    }
};
