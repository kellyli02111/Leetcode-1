class Solution {
public:
    bool isStroboPair(char a, char b){
        if(a == '0' && b == '0') return true;
        if(a == '1' && b == '1') return true;
        if(a == '6' && b == '9') return true;
        if(a == '8' && b == '8') return true;
        if(a == '9' && b == '6') return true;
        return false;
    }

    bool isStrobogrammatic(string num) {
        int n = num.size();
        for(int i = 0; i < (n + 1) / 2; i++){
            if(!isStroboPair(num[i], num[n - 1 - i])){
                return false;
            }
        }
        return true;
    }
};
