class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> charMap;
        unordered_set<string> wordSet;
        int n = pattern.size();
        int searchStart = 0;
        for(int i = 0; i < n; i++){
            if(str.empty()) return false;
            int pos = str.find(" ", searchStart);
            string word;
            if(pos == std::string::npos){
                word = str.substr(searchStart);
                str = "";
            }
            else{
                word = str.substr(searchStart, pos - searchStart);
                searchStart = pos + 1;
            }
            if(charMap.find(pattern[i]) == charMap.end()){
                if(wordSet.find(word) != wordSet.end()) return false;
                charMap[pattern[i]] = word;
                wordSet.insert(word);
            }
            else{
                if(charMap[pattern[i]] != word){
                    return false;
                }
            }
        }
        if(!str.empty()) return false;
        return true;
    }
};
