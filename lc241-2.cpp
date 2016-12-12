class Solution {
public:
    int compute(int a, int b, char op){
        switch(op){
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
        }
        return 0;
    }
    
    string generateKey(int start, int end){
        return to_string(start) + "-" + to_string(end);
    }
    
    vector<int> diffWaysToCompute(string input) {
        unordered_map<string, vector<int>> memo;
        return diffWaysToComputeHelper(input, 0, input.size() - 1, memo);
    }

    vector<int> diffWaysToComputeHelper(string input, int start, int end, unordered_map<string, vector<int>>& memo) {
        int num = 0;
        string key = generateKey(start, end);
        if(memo.find(key) != memo.end()){
            return memo[key];
        }
        int i = start;
        for(; i <= end; i++){
            if(isdigit(input[i])){
                num = num * 10 + input[i] - '0';
            }
            else{
                break;
            }
        }
        if(i > end) return {num};
        vector<int> lefts, rights, res;
        for(int i = start; i <= end; i++){
            if(isdigit(input[i])) continue;
            lefts = diffWaysToComputeHelper(input, start, i - 1, memo);
            rights = diffWaysToComputeHelper(input, i + 1, end, memo);
            for(int j = 0; j < lefts.size(); j++){
                for(int k = 0; k < rights.size(); k++){
                    res.push_back(compute(lefts[j], rights[k], input[i]));
                }
            }
        }
        memo[key] = res;
        return res;
    }
};
