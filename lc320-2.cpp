class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        generateAbbreviationsHelper(res, word, "", 0, false);
        return res;
    }
    
    void generateAbbreviationsHelper(vector<string>& res, string& word, string abbr, int i, bool preNum){
        if(i == word.size()){
            res.push_back(abbr);
            return;
        }
        generateAbbreviationsHelper(res, word, abbr + word[i], i + 1, false);
        //只在上一个不是数字的时候才能加数字
        if(!preNum){
            for(int len = 1; i + len <= word.size(); len++){
                generateAbbreviationsHelper(res, word, abbr + to_string(len), i + len, true);
            }
        }
    }
};
