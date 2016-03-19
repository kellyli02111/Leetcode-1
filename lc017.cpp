class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> str = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<int> len;
        for(int i = 0; i < str.size(); i++){
            len.push_back(str[i].size());
        }
        vector<string> res;
        vector<string> tmp;
        if(digits.size() == 0) return res;
        res.push_back("");
        for(int i = 0; i < digits.size(); i++){
            tmp = res;
            res.clear();
            int pos = digits[i] - '2';
            for(int j = 0; j < tmp.size(); j++){
                for(int k = 0; k < len[pos]; k++){
                    res.push_back(tmp[j] + str[pos][k]);
                }
            }
        }
        return res;
    }
};
