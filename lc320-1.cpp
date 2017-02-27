class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        int n = word.size();
        int powN = pow(2, n);
        for(int i = 0; i < powN; i++){
            string cur = "";
            int count = 0;
            for(int j = n - 1; j >= 0; j--){
                if((i >> j) & 1 == 1){
                    count++;
                    if(j == 0){
                        cur = cur + to_string(count);
                    }
                }
                else{
                    if(count != 0){
                        cur = cur + to_string(count);
                        count = 0;
                    }
                    cur.push_back(word[n - 1 - j]);
                }
            }
            res.push_back(cur);
        }
        return res;
    }
};
