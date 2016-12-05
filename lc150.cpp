class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(int i = 0; i < tokens.size(); i++){
            if(!isOp(tokens[i])){
                stk.push(stoi(tokens[i]));
            }
            else{
                cal(stk, tokens[i]);
            }
        }
        return stk.top();
    }
    
    void cal(stack<int>& stk, string op){
        int b = stk.top();
        stk.pop();
        int a = stk.top();
        stk.pop();
        if(op == "+") stk.push(a + b);
        if(op == "-") stk.push(a - b);
        if(op == "*") stk.push(a * b);
        if(op == "/") stk.push(a / b);
    }
    
    
    bool isOp(string op){
        return (op == "+" || op == "-" || op == "*" || op == "/");
    }
};
