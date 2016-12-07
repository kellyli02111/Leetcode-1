class TrieNode{
public:
    TrieNode* child[26];
    string str;
    
    TrieNode(){
        for(int i = 0; i < 26; i++){
            child[i] = NULL;
        }
        str = "";
    }
};

class Trie{
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    
    void insert(string s){
        TrieNode* cur = root;
        for(int i = 0; i < s.size(); i++){
            if(cur->child[s[i] - 'a'] == NULL){
                cur->child[s[i] - 'a'] = new TrieNode();
            }
            cur = cur->child[s[i] - 'a'];
        }
        cur->str = s;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if(board.size() == 0 || board[0].size() == 0 || words.size() == 0) return res;
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> flag(m, vector<bool>(n, false));
        Trie tr;
        for(int i = 0; i < words.size(); i++){
            tr.insert(words[i]);
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0 ; j < board[0].size(); j++){
                if(tr.root->child[board[i][j] - 'a'] != NULL){
                    search(board, flag, tr.root->child[board[i][j] - 'a'], i, j, res);
                }
            }
        }
        return res;
    }
    
    void search(vector<vector<char>>& board, vector<vector<bool>>& flag, TrieNode* node, int i, int j, vector<string>& res){
        if(node->str != ""){
            res.push_back(node->str);
            node->str = "";
        }
        flag[i][j] = true;
        int nx = i - 1;
        int ny = j;
        
        if(nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && !flag[nx][ny] && (node->child[board[nx][ny] - 'a'] != NULL)){
            search(board, flag, node->child[board[nx][ny] - 'a'], nx, ny, res);
        }
        nx = i + 1;
        ny = j;
        if(nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && !flag[nx][ny] && (node->child[board[nx][ny] - 'a'] != NULL)){
            search(board, flag, node->child[board[nx][ny] - 'a'], nx, ny, res);
        }
        nx = i;
        ny = j - 1;
        if(nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && !flag[nx][ny] && (node->child[board[nx][ny] - 'a'] != NULL)){
            search(board, flag, node->child[board[nx][ny] - 'a'], nx, ny, res);
        }
        nx = i;
        ny = j + 1;
        if(nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && !flag[nx][ny] && (node->child[board[nx][ny] - 'a'] != NULL)){
            search(board, flag, node->child[board[nx][ny] - 'a'], nx, ny, res);
        }
        flag[i][j] = false;
    }
};
