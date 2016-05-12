class Solution {
public:
    string countAndSay(int n) {
        string m = "1";
        for(int i = 0; i < n - 1; i++){
            m = say(m);
        }
        return m;
    }
    string say(string s){
        string res = "";
        int count = 1;
        char last = s.back();
        s.pop_back();
        while(!s.empty()){
            char cur = s.back();
            s.pop_back();
            if(cur == last) count++;
            else{
                res = to_string(count) + last + res;
                last = cur;
                count = 1;
            }
        }
        res = to_string(count) + last + res;
        return res;
    }
};
