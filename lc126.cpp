class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector<vector<string>> res;
        vector<string> path;
        unordered_set<string> cur;
        unordered_set<string> next;
        unordered_map<string, vector<string>> um;
        wordList.insert(beginWord);
        wordList.insert(endWord);
        cur.insert(beginWord);
        path.push_back(beginWord);
        
        while(true){
            //delete nodes of the same level from the wordList
            for(auto it = cur.begin(); it != cur.end(); it++){
                wordList.erase(*it);
            }
            //find all next level nodes
            for(auto it = cur.begin(); it != cur.end(); it++){
                findDict(um, wordList, next, *it);
            }
            //all possible paths broken
            if(next.empty()) return res;
            //first (shortest path) path reached end, stop building new adjacency list, otherwise the other possible path will be longer
            if(next.find(endWord) != next.end()){
                output(um, res, path, beginWord, endWord);
                return res;
            }
            cur = next;
            next.clear();
        }
        //no possible path found
        return res;
    }
    
    void findDict(unordered_map<string, vector<string>>& um, unordered_set<string>& wordList, unordered_set<string>& next, string str){
        /*used to build adjacency unordered_set for each node (string)
        notice that 3 types of nodes have been deleted, or skipped from wordList: 
        1. previouly traversed (previous levels)
        2. nodes at the same level
        3. nodes with the same values*/
        int n = str.size();
        string s = str;
        for(int i = 0; i < n; i++){
            char c = s[i];
            for(char tmp = 'a'; tmp <= 'z'; tmp++){
                if(tmp == c) continue;
                s[i] = tmp;
                if(wordList.find(s) != wordList.end()){
                    next.insert(s);
                    um[str].push_back(s);
                }
            }
            s[i] = c;
        }
    }
    
    void output(unordered_map<string, vector<string>>& um, vector<vector<string>>& res, vector<string>& path, string& begin, string& end){
        //used to traverse the adjacency list to output path
        if(begin == end){
            res.push_back(path);
        }
        else{
            for(int i = 0; i < um[begin].size(); i++){
                path.push_back(um[begin][i]);
                output(um, res, path, um[begin][i], end);
                path.pop_back();
            }
        }
    }
};
