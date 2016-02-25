class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        queue<int> zeroInDegree;
        int n = prerequisites.size();
        vector<int> res;
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
            zeroInDegree.pop();
            res.push_back(cur);
            for(int i = 0; i < n; i++){
                if(prerequisites[i].second == cur){
                    inDegree[prerequisites[i].first]--;
                    if(inDegree[prerequisites[i].first] == 0){
                        zeroInDegree.push(prerequisites[i].first);
                    }
                }
            }
        }
        return (res.size() == numCourses);
    }
};
