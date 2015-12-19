//Segment Tree
class segTreeNode{
public:
    int val;
    int low;
    int high;
    segTreeNode *left;
    segTreeNode *right;
    segTreeNode(int start, int end, vector<int> &nums){
        low = start;
        high = end;
        if(start == end){
            val = nums[start];
            left = NULL;
            right = NULL;
        }
        else{
            int mid = (start + end) / 2;
            left = new segTreeNode(start, mid, nums);
            right = new segTreeNode(mid + 1, end, nums);
            val = left->val + right->val;
        }
    }
};

class NumArray {
    segTreeNode* root;
    vector<int> numArray;
public:
    NumArray(vector<int> &nums) {
        numArray = nums;
        if(nums.empty()) root == NULL;
        else{
            int n = nums.size();
            root = new segTreeNode(0, n - 1, nums);
        }
    }

    void update(int i, int val) {
        int diff = val - numArray[i];
        int n = numArray.size();
        numArray[i] = val;
        segTreeNode* cur = root;
        while(cur->low <=i && cur->high >= i){
            cur->val = cur->val + diff;
            if(cur->low == cur->high) break;
            int mid = (cur->low + cur->high) / 2;
            if(mid >= i){
                cur = cur->left;
            }
            else{
                cur = cur->right;
            }
        }
    }

    int sumRange(int i, int j) {
        return sumRange(i, j, root);
    }
    int sumRange(int i, int j, segTreeNode* node) {
        if(node == NULL) return 0;
        if(node->low > j || node->high < i) return 0;
        if(node->low >= i && node->high <= j) return node->val;
        else{
            return sumRange(i, j, node->left) + sumRange(i, j, node->right);
        }
    }
};
