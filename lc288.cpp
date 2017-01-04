class ValidWordAbbr {
private:
    unordered_map<string, vector<string>> um;
    
    string abbr(string str){
        if(str.size() <= 2) return str;
        string res = "";
        res.append(1, str[0]);
        res = res + to_string(str.size() - 2);
        res.append(1, str[str.size() - 1]);
        return res;
    }
    
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for(int i = 0; i < dictionary.size(); i++){
            string abr = abbr(dictionary[i]);
            um[abr].push_back(dictionary[i]);
        }
    }

    bool isUnique(string word) {
        string abr = abbr(word);
        vector<string> wordList = um[abr];
        for(int i = 0; i < wordList.size(); i++){
            if(wordList[i] != word) return false;
        }
        return true;
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");
