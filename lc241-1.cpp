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

    vector<int> diffWaysToCompute(string input) {
        int num = 0;
        int i = 0;
        for(; i < input.size(); i++){
            if(isdigit(input[i])){
                num = num * 10 + input[i] - '0';
            }
            else{
                break;
            }
        }
        if(i == input.size()) return {num};
        vector<int> lefts, rights, res;
        for(int i = 0; i < input.size(); i++){
            if(isdigit(input[i])) continue;
            lefts = diffWaysToCompute(input.substr(0, i));
            rights = diffWaysToCompute(input.substr(i + 1, input.size() - i - 1));
            for(int j = 0; j < lefts.size(); j++){
                for(int k = 0; k < rights.size(); k++){
                    res.push_back(compute(lefts[j], rights[k], input[i]));
                }
            }
        }
        return res;
    }
};
