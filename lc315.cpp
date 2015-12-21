class segTreeNode{
public:
    int val;
    int count;
    int leftSize;
    segTreeNode *left;
    segTreeNode *right;
    segTreeNode(int value){
        val = value;
        count = 1;
        leftSize = 0;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
        if(nums.empty()) return res;
        int n = nums.size();
        segTreeNode* root = new segTreeNode(INT_MAX);
        for(int i = n - 1; i >= 0; i--){
            int resVal = 0;
            segTreeNode* cur = root;
            while(cur != NULL){
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
                        segTreeNode* newNode = new segTreeNode(nums[i]);
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
                        segTreeNode* newNode = new segTreeNode(nums[i]);
                        cur->right = newNode;
                        res.push_back(resVal);
                        break;
                    }
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
