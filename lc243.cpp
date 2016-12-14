class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int res = INT_MAX;
        int idx1 = -1;
        int idx2 = -1;
        for(int i = 0; i < words.size(); i++){
            if(words[i] == word1){
                idx1 = i;
            }
            if(words[i] == word2){
                idx2 = i;
            }
            if(idx1 >= 0 && idx2 >= 0){
                res = min(res, abs(idx1 - idx2));
            }
        }
        return res;
    }
};
