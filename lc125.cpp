class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() == 0) return true;
        int begin = 0;
        int end = s.size() - 1;
        while(begin < end){
            while(begin < s.size() && !isalnum(s[begin])) begin++;
            while(end >=0 && !isalnum(s[end])) end--;
            if(begin >= end) return true;
            if(tolower(s[begin]) != tolower(s[end])) return false;
            begin++;
            end--;
        }
        return true;
    }
};
