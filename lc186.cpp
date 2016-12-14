class Solution {
public:
    void reverseWords(string &s) {
        if(s.size() == 0) return;
        reverse(s.begin(), s.end());
        int left = 0;
        int right = 0;
        while(right < s.size()){
            if(s[right] != ' '){
                right++;
            }
            else{
                reverseString(s, left, right - 1);
                right++;
                left = right;
            }
        }
        reverseString(s, left, s.size() - 1);
    }
    
    void reverseString(string& s, int left, int right){
        while(left < right){
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};
