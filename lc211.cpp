class TrieNode{
public:
    TrieNode* child[26];
    bool isEnd;
    
    TrieNode(){
        for(int i = 0; i < 26; i++){
            child[i] = false;
        }
        isEnd = false;
    }
};



class WordDictionary {
public:
    TrieNode* root;
    
    WordDictionary(){
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* cur = root;
        for(int i = 0; i < word.size(); i++){
            if(cur->child[word[i] - 'a'] == NULL){
                cur->child[word[i] - 'a'] = new TrieNode();
            }
            cur = cur->child[word[i] - 'a'];
        }
        cur->isEnd = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search(word, root, 0);
    }
    
    bool search(string word, TrieNode* node, int i){
        if(i == word.size()) return node->isEnd;
        if(word[i] == '.'){
            for(int j = 0; j < 26; j++){
                if(node->child[j] == NULL) continue;
                if(search(word, node->child[j], i + 1)) return true;
            }
            return false;
        }
        else{
            if(node->child[word[i] - 'a'] == NULL) return false;
            return search(word, node->child[word[i] - 'a'], i + 1);
        }
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
