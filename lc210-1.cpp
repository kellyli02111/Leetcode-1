class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<int> res;
        queue<int> zeroInDegree;
        int n = prerequisites.size();
        for(int i = 0; i < n; i++){
            inDegree[prerequisites[i].first]++;
        }
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0){
                zeroInDegree.push(i);
            }
        }
        while(!zeroInDegree.empty()){
            int cur = zeroInDegree.front();
            res.push_back(cur);
            zeroInDegree.pop();
            for(int i = 0; i < n; i++){
                if(prerequisites[i].second == cur){
                    inDegree[prerequisites[i].first]--;
                    if(inDegree[prerequisites[i].first] == 0){
                        zeroInDegree.push(prerequisites[i].first);
                    }
                }
            }
        }
        if(res.size() == numCourses) return res;
        else return vector<int>{};
    }
};
