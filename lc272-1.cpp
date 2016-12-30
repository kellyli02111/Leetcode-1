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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> vec;
        inorder(root, vec);
        double diff = numeric_limits<double>::max();
        int index = 0;
        for(int i = 0; i < vec.size(); i++){
            if(abs(vec[i] - target) < diff){
                diff = abs(vec[i] - target);
                index = i;
            }
        }
        vector<int> res;
        int left = index - 1;
        int right = index + 1;
        for(int i = 0; i < k; i++){
            res.push_back(vec[index]);
            if(left >= 0 && right < vec.size()){
                if(abs(vec[left] - target) < abs(vec[right] - target)){
                    index = left;
                    left--;
                }
                else{
                    index = right;
                    right++;
                }
            }
            else if(right < vec.size()){
                index = right;
                right++;
            }
            else{
                index = left;
                left--;
            }
        }
        return res;
    }
    
    void inorder(TreeNode* root, vector<int>& vec){
        if(root == NULL) return;
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }
};
