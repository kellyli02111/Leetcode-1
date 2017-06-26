class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.size();
        if(n == 0) return false;
        vector<string> temp;
        int i = 0;
        while(i < n){
            string s;
            if(preorder[i] != ',' && preorder[i] != '#'){
                while(i < n && preorder[i] != ',' && preorder[i] != '#'){
                    s = s + preorder[i];
                    i++;
                }
                temp.push_back(s);
            }
            else if(preorder[i] == '#'){
                temp.push_back("#");
                i++;
            }
            i++;
        }
        stack<string> stk;
        for(int i = 0; i < temp.size(); i++){
            if(temp[i] != "#"){
                stk.push(temp[i]);
            }
            else{
                while(!stk.empty() && stk.top() == "#"){
                    stk.pop();
                    if(stk.empty()) return false;
                    stk.pop();
                }
                stk.push("#");
            }
        }
        return (stk.size() == 1 && stk.top() == "#");
    }
};
