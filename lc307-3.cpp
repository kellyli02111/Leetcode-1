class NumArray {
    vector<int> segTree;
    vector<int> data;
public:
    NumArray(vector<int> nums) {
        int n = nums.size();
        if(n == 0) return;
        data = nums;
        int i = 1;
        while(i < n){
            i = i * 2;
        }
        segTree.resize(2 * i - 1, 0);
        createSegTree(nums, segTree, 0, n - 1, 0);
    }
    
    void createSegTree(vector<int>& nums, vector<int>& segTree, int low, int high, int pos){
        if(low == high){
            segTree[pos] = nums[low];
            return;
        }
        int mid = low + (high - low) / 2;
        createSegTree(nums, segTree, low, mid, 2 * pos + 1);
        createSegTree(nums, segTree, mid + 1, high, 2 * pos + 2);
        segTree[pos] = segTree[2 * pos + 1] + segTree[2 * pos + 2];
    }
    
    void update(int i, int val) {
        update_sub(0, data.size() - 1, i, val, segTree, 0);
        data[i] = val;
    }
    
    void update_sub(int low, int high, int& i, int& val, vector<int>& segTree, int pos){
        segTree[pos] = segTree[pos] + (val - data[i]);
        if(low < high){
            int mid = low + (high - low) / 2;
            if(mid >= i){
                update_sub(low, mid, i, val, segTree, 2 * pos + 1);
            }
            else{
                update_sub(mid + 1, high, i, val, segTree, 2* pos + 2);
            }
        }
    }
    
    int sumRange(int i, int j) {
        return sumRange_sub(i, j, 0, data.size() - 1, 0);
    }
    
    int sumRange_sub(int& i, int& j, int low, int high, int pos){
        if(low >= i && high <= j){
            return segTree[pos];
        }
        if(high < i || low > j){
            return 0;
        }
        else{
            int mid = low + (high - low) / 2;
            return (sumRange_sub(i, j, low, mid, 2 * pos + 1) + sumRange_sub(i, j, mid + 1, high, 2 * pos + 2));
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
