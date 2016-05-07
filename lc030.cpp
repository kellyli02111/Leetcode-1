class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int n = words.size();
        if(n == 0) return res;
        int len = words[0].size();
        if(len == 0) return res;
        if(s.size() < n * len) return res;
        
        map<string, int> m;
        for(int i = 0; i < n; i++){
            m[words[i]]++;
        }
        for(int i = 0; i <= s.size() - n * len; i++){
            bool flag = true;
            map<string, int> curMap;
            for(int j = i; j < i + n * len; j = j + len){
                string temp = s.substr(j, len);
                curMap[temp]++;
                if(curMap[temp] > m[temp]){
                    flag = false;
                    break;
                }
            }
            if(flag == true){
                res.push_back(i);
            }
        }
        return res;
    }
};
