//基于BFS的Topological Sort，对每一个edge的终点增加入度，从入度为0的开始做BFS，遍历到的顶点入度减1，并把入度减到0的顶点放回到queue里
class Solution {
public:
    string alienOrder(vector<string>& words) {
        int n = words.size();
        if(n == 0) return "";
        string res = "";
        vector<vector<int>> edges;
        vector<int> inDegree(26, 0);
        vector<int> exist(26, false);
        
        //在字典中没出现的字母不考虑
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words[i].size(); j++){
                exist[words[i][j] - 'a'] = true;
            }
        }
        
        for(int i = 1; i < words.size(); i++){
            //新增加test case，必须detect是否mismatch存在，否则如果i - 1为abc，i为ab的话，下面的loop会通过，但实际上为invalid
            bool misMatch = false;
            for(int j = 0; j < min(words[i-1].size(), words[i].size()); j++){
                if(words[i - 1][j] == words[i][j]) continue;
                else{
                    inDegree[words[i][j] - 'a']++;
                    edges.push_back(vector<int>{words[i - 1][j] - 'a', words[i][j] - 'a'});
                    misMatch = true;
                    break;
                }
            }
            //没有detect到mismatch，但前一个串比后一个要长，为invalid
            if(misMatch == false && words[i - 1].size() > words[i].size()){
                return "";
            }
        }
        queue<int> q;
        for(int i = 0; i < inDegree.size(); i++){
            if(inDegree[i] == 0 && exist[i]){
                q.push(i);
                res.append(1, 'a' + i);
            }
        }
        while(!q.empty()){
            int a = q.front();
            q.pop();
            for(int i = 0; i < edges.size(); i++){
                if(edges[i][0] == a){
                    inDegree[edges[i][1]]--;
                    if(inDegree[edges[i][1]] == 0){
                        q.push(edges[i][1]);
                        res.append(1, 'a' + edges[i][1]);
                    }
                }
            }
        }
        //如果有环，则最终会有入度不为0的点，比如a->b, b->a不会被queue执行
        for(int i = 0; i < inDegree.size(); i++){
            if(inDegree[i] != 0) return "";
        }
        return res;
    }
};
