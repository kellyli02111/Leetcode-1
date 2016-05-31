class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() == 0 || s.size() < t.size()) return "";
        vector<int> appearedCount(256, 0);
        vector<int> expectedCount(256, 0);
        for(int i = 0; i < t.size(); i++){
            expectedCount[t[i]]++;
        }
        int minV = INT_MAX;
        int minStart = 0;
        int appeared = 0;
        int windowStart = 0;
        for(int windowEnd = 0; windowEnd < s.size(); windowEnd++){
            if(expectedCount[s[windowEnd]] > 0){
                appearedCount[s[windowEnd]]++;
                if(appearedCount[s[windowEnd]] <= expectedCount[s[windowEnd]]){
                    appeared++;
                }
            }
            if(appeared == t.size()){
                while(appearedCount[s[windowStart]] > expectedCount[s[windowStart]] || expectedCount[s[windowStart]] == 0){
                    appearedCount[s[windowStart]]--;
                    windowStart++;
                }
                if(minV > windowEnd - windowStart + 1){
                    minV = windowEnd - windowStart + 1;
                    minStart = windowStart;
                }
            }
        }
        if(minV == INT_MAX) return "";
        return s.substr(minStart, minV);
    }
};
