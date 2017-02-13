/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<pair<int, TreeNode*>> q;
        map<int, vector<int>> m;
        if(root == NULL) return res;
        q.push(make_pair(0, root));
        while(!q.empty()){
            auto a = q.front();
            q.pop();
            m[a.first].push_back(a.second->val);
            if(a.second->left){
                q.push(make_pair(a.first - 1, a.second->left));
            }
            if(a.second->right){
                q.push(make_pair(a.first + 1, a.second->right));
            }
        }
        for(auto it = m.begin(); it != m.end(); it++){
            res.push_back(it->second);
        }
        return res;
    }
};
