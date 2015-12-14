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
            if (aIndex >=0 && bIndex >=0){
                int aInt = a[aIndex] - '0';
                int bInt = b[bIndex] - '0';
                int cInt = aInt ^ bInt ^ carry;
                carry = aInt & bInt | carry & (aInt ^ bInt);
                res = (char)(cInt + '0') + res;
                aIndex--;
                bIndex--;
                continue;
            }
            if (aIndex >=0){
                int aInt = a[aIndex] - '0';
                int cInt = aInt ^ carry;
                carry = aInt & carry;
                res = (char)(cInt + '0') + res;
                aIndex--;
                continue;
            }
            if (bIndex >=0){
                int bInt = b[bIndex] - '0';
                int cInt = bInt ^ carry;
                carry = bInt & carry;
                res = (char)(cInt + '0') + res;
                bIndex--;
                continue;
            }
            if(carry != 0){
                res = (char)(carry + '0') + res;
                carry = 0;
                continue;
            }
        }
        return res;
    }
};
