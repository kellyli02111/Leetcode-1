class avlTreeNode{
public:
    int val;
    int count;
    int leftSize;
    int depth;
    avlTreeNode *left;
    avlTreeNode *right;
    avlTreeNode(int value){
        val = value;
        count = 1;
        leftSize = 0;
        left = NULL;
        right = NULL;
        depth = 1;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
        if(nums.empty()) return res;
        int n = nums.size();
        avlTreeNode* dummy = new avlTreeNode(INT_MAX);
        avlTreeNode* root = new avlTreeNode(nums[n - 1]);
        res.push_back(0);
        dummy->left = root;
        for(int i = n - 2; i >= 0; i--){
            int resVal = 0;
            avlTreeNode* cur = dummy->left;
            vector<avlTreeNode*> path;
            path.push_back(dummy);
            while(cur != NULL){
                path.push_back(cur);
                if(cur->val == nums[i]){
                    cur->count++;
                    resVal = resVal + cur->leftSize;
                    res.push_back(resVal);
                    break;
                }
                if(cur->val > nums[i]){
                    cur->leftSize = cur->leftSize + 1;
                    if(cur->left != NULL){
                        cur = cur->left;
                    }
                    else{
                        avlTreeNode* newNode = new avlTreeNode(nums[i]);
                        cur->left = newNode;
                        res.push_back(resVal);
                        break;
                    }
                }
                else{
                    resVal = resVal + cur->leftSize + cur->count;
                    if(cur->right != NULL){
                        cur = cur->right;
                    }
                    else{
                        avlTreeNode* newNode = new avlTreeNode(nums[i]);
                        cur->right = newNode;
                        res.push_back(resVal);
                        break;
                    }
                }
            }
            int pathSize = path.size();
            for(int j = 0; j < pathSize; j++){
                path[j]->depth = max(path[j]->depth, pathSize + 1 - j);
            }
            for(int j = pathSize - 1; j >= 1; j--){
                int leftDepth = getDepth(path[j]->left);
                int rightDepth = getDepth(path[j]->right);
                if(leftDepth - rightDepth > 1){
                    avlTreeNode* temp = path[j]->left;
                    if(getDepth(temp->left) >= getDepth(temp->right)){
                        rotateLL_violate(path[j], path[j - 1]);
                    }
                    else{
                        rotateLR_violate(path[j], path[j - 1]);
                    }
                }
                if(rightDepth - leftDepth > 1){
                    avlTreeNode* temp = path[j]->right;
                    if(getDepth(temp->right) >= getDepth(temp->left)){
                        rotateRR_violate(path[j], path[j - 1]);
                    }
                    else{
                        rotateRL_violate(path[j], path[j - 1]);
                    }
                }
            }
        }
        //string str = serialize(root->left);
        reverse(res.begin(), res.end());
        return res;
    }
    
    void rotateRR(avlTreeNode* root, avlTreeNode* pre){
        avlTreeNode* next = root->right;
        next->leftSize = root->leftSize + next->leftSize + root->count;
        if(pre->left == root){
            pre->left = next;
            //pre->leftSize = next->leftSize + next->count;
        }
        else{
            pre->right = next;
        }
        root->right = next->left;
        next->left = root;
    }
    
    void rotateLL(avlTreeNode* root, avlTreeNode* pre){
        avlTreeNode* next = root->left;
        if(next->right != NULL){
            root->leftSize = root->leftSize - next->count - next->leftSize;
        }
        else{
            root->leftSize = 0;
        }
        if(pre->left == root){
            pre->left = next;
        }
        else{
            pre->right = next;
        }
        root->left = next->right;
        next->right = root;
    }
    void rotateRR_violate(avlTreeNode* root, avlTreeNode* pre){
        root->depth = root->depth - 2;
        pre->depth = pre->depth - 1;
        rotateRR(root, pre);
    }
    void rotateRR_noviolate(avlTreeNode* root, avlTreeNode* pre){
        root->depth = root->depth - 1;
        root->right->depth = root->right->depth + 1;
        rotateRR(root, pre);
    }
    void rotateLL_violate(avlTreeNode* root, avlTreeNode* pre){
        root->depth = root->depth - 2;
        pre->depth = pre->depth - 1;
        rotateLL(root, pre);
    }
    void rotateLL_noviolate(avlTreeNode* root, avlTreeNode* pre){
        root->depth = root->depth - 1;
        root->left->depth = root->left->depth + 1;
        rotateLL(root, pre);
    }
    void rotateRL_violate(avlTreeNode* root, avlTreeNode* pre){
        rotateLL_noviolate(root->right, root);
        rotateRR_violate(root, pre);
    }
    
    void rotateLR_violate(avlTreeNode* root, avlTreeNode* pre){
        rotateRR_noviolate(root->left, root);
        rotateLL_violate(root, pre);
    }
    int getDepth(avlTreeNode* root) {
        if(root == NULL){
            return 0;
        }
        return root->depth;
    }
};
