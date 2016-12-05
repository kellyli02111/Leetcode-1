//http://www.cnblogs.com/grandyang/p/4284205.html
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        int mask = 0x3fffffff;
        unordered_map<int, int> m;
        int i = 0;
        int cur = 0;
        while(i < 9){
            cur = (cur << 3) | (s[i] & 7);
            i++;
        }
        while(i < s.size()){
            cur = (cur << 3) & mask | (s[i] & 7);
             i++;
            if(m.find(cur) != m.end()){
                if(m[cur] == 0){
                    res.push_back(s.substr(i - 10, 10));
                    m[cur] = 1;
                }
            }
            else{
                m[cur] = 0;
            }
        }
        return res;
    }
};
