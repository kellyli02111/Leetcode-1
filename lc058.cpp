class Solution {
public:
    int lengthOfLastWord(string s) {
        int ind1 = s.find_last_not_of(' ');
        s = s.substr(0, ind1 + 1);
        int ind2 = s.find_last_of(' ');
        if(ind2 >= s.size()) return s.size();
        else{
            return s.size() - ind2 - 1;
        }
    }
};
