//先生成半个string，再生成整个
class Solution {
public:
    vector<string> generatePalindromes(string s) {
        unordered_map<char, int> um;
        vector<string> res;
        for(int i = 0; i < s.size(); i++){
            if(um.find(s[i]) == um.end()){
                um[s[i]] = 1;
            }
            else{
                um[s[i]]++;
            }
        }
        string mid = "";
        string halfs = "";
        for(auto it = um.begin(); it != um.end(); it++){
            if(it->second % 2 == 1){
                mid = mid + it->first;
            }
            //可以用string(num, char) 来生成一个fill好的string
            halfs = halfs + string(it->second / 2, it->first);
        }
        if(mid.size() > 1) return res;
        if(halfs.size() == 0){
            res.push_back(mid);
            return res;
        }
        
        sort(halfs.begin(), halfs.end());
        vector<bool> used(halfs.size(), false);
        string per = "";
        findPermute(halfs, used, per, res);
        if(mid.size() == 0){
            for(int i = 0; i < res.size(); i++){
                string t = res[i];
                reverse(t.begin(), t.end());
                res[i] = res[i] + t;
            }
        }
        else{
            for(int i = 0; i < res.size(); i++){
                string t = res[i];
                reverse(t.begin(), t.end());
                res[i] = res[i] + mid + t;
            }
        }
        return res;
    }
    
    //生成没有重复的permutation
    void findPermute(string& s, vector<bool>& used, string& per, vector<string>& res){
        if(s.size() == per.size()){
            res.push_back(per);
            return;
        }
        for(int i = 0; i < s.size(); i++){
            if(used[i] == false){
                //对于重复的情况，只考虑从第一个开始的连续串，中间任意处断开的均为重复
                if(i > 0 && s[i] == s[i - 1] && used[i - 1] == false) continue;
                used[i] = true;
                per.push_back(s[i]);
                findPermute(s, used, per, res);
                per.pop_back();
                used[i] = false;
            }
        }
    }
};
