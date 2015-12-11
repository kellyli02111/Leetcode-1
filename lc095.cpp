class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0){
            vector<TreeNode*> res;
            return res;
        }
        return createTrees(1, n);
    }
    
    vector<TreeNode*> createTrees(int start, int end) {
        vector<TreeNode*> res;
        if(start > end){
            res.push_back(NULL);
            return res;
        }
        if(start == end){
            TreeNode* newNode = new TreeNode(start);
            res.push_back(newNode);
            return res;
        }
        for(int i = start; i <= end; i++){
            vector<TreeNode*> leftTree = createTrees(start, i - 1);
            vector<TreeNode*> rightTree = createTrees(i + 1, end);
            int leftSize = leftTree.size();
            int rightSize = rightTree.size();
            for(int j = 0; j < leftSize; j++){
                for(int k = 0; k < rightSize; k++){
                    TreeNode* newNode = new TreeNode(i);
                    newNode->left = leftTree[j];
                    newNode->right = rightTree[k];
                    res.push_back(newNode);
                }
            }
        }
        return res;
    }
};
