bool comp(string a, string b){
    return ((a + b) < (b + a));
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strVec;
        for(int i = 0; i < nums.size(); i++){
            strVec.push_back(to_string(nums[i]));
        }
        sort(strVec.begin(), strVec.end(), comp);
        string res = "";
        for(int i = strVec.size() - 1; i >= 0; i--){
            res = res + strVec[i];
        }
        while((res.size() > 1) && res[0] == '0'){
            res.erase(res.begin());
        }
        return res;
    }
};
