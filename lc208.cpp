class TrieNode {
public:
    vector<TrieNode*> child;
    bool is_end;
    // Initialize your data structure here.
    TrieNode() {
        child = vector<TrieNode*>(26, NULL);
        is_end = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* cur = root;
        for(int i = 0; i < word.size(); i++){
            if(cur->child[word[i] - 'a'] == NULL){
                cur->child[word[i] - 'a'] = new TrieNode();
            }
            cur = cur->child[word[i] - 'a'];
        }
        cur->is_end = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* cur = root;
        for(int i = 0; i < word.size(); i++){
            if(cur->child[word[i] - 'a'] == NULL){
                return false;
            }
            cur = cur->child[word[i] - 'a'];
        }
        return cur->is_end;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(int i = 0; i < prefix.size(); i++){
            if(cur->child[prefix[i] - 'a'] == NULL){
                return false;
            }
            cur = cur->child[prefix[i] - 'a'];
        }
        return true;
    }

private:
    TrieNode* root;
};
