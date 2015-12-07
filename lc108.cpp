//时间复杂度为 O(n) 基础公式为 T(n) = C + 2T(n/2), 因为每一层不管tree大小都只花一个node的时间。
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return NULL;
        int n = nums.size();
        return sortedArrayToBST_sub(nums, 0, n - 1);
    }
    
    TreeNode* sortedArrayToBST_sub(vector<int>& nums, int a, int b){
        int mid = (a + b) / 2;
        if(b - a == 0){
            TreeNode* res = new TreeNode(nums[b]);
            return res;
        }
        if(b - a == 1){
            TreeNode* res = new TreeNode(nums[b]);
            res->left = sortedArrayToBST_sub(nums, a, a);
            return res;
        }
        TreeNode* res = new TreeNode(nums[mid]);
        res->left = sortedArrayToBST_sub(nums, a, mid - 1);
        res->right = sortedArrayToBST_sub(nums, mid + 1, b);
        return res;
    }
};
