//每次遇到新的大值的时候，将stack里比它小的值全部取出，并更新以后限制的最小值
//如果与最小值有violation,便不是合法的preorder
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> stk;
        int minNum = INT_MIN;
        for(int i = 0; i < preorder.size(); i++){
            if(preorder[i] < minNum){
                return false;
            }
            while(!stk.empty() && preorder[i] > stk.top()){
                minNum = stk.top();
                stk.pop();
            }
            stk.push(preorder[i]);
        }
        return true;
    }
};
