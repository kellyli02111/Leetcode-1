class WordDistance {
public:
unordered_map<string, vector<int>> um;
    WordDistance(vector<string>& words) {
        for(int i = 0; i < words.size(); i++){
            um[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        int res = INT_MAX;
        vector<int> vec1 = um[word1];
        vector<int> vec2 = um[word2];
        int m = vec1.size();
        int n = vec2.size();
        int i = 0;
        int j = 0;
        while(i < vec1.size() && j < vec2.size()){
            res = min(res, abs(vec1[i] - vec2[j]));
            if(vec1[i] < vec2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return res;
    }
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");
