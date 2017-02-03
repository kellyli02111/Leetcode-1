//http://www.cnblogs.com/grandyang/p/4985506.html
class NumArray {
    vector<int> segTree;
    vector<int> data;
public:
    NumArray(vector<int> nums) {
        data.resize(nums.size() + 1);
        segTree.resize(nums.size() + 1);
        for(int i = 0; i < nums.size(); i++){
            update(i, nums[i]);
        }
    }
    
    void update(int i, int val) {
        int diff = val - data[i + 1];
        for(int j = i + 1; j < data.size(); j = j + (j & (j ^ (j - 1)))){
            segTree[j] = segTree[j] + diff;
        }
        data[i + 1] = val;
    }
    
    
    int sumRange(int i, int j) {
        return (getSum(j + 1) - getSum(i));
    }
    
    int getSum(int i){
        int res = 0;
        for(int j = i; j > 0; j = j - (j & (j ^ (j - 1)))){
            res = res + segTree[j];
        }
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
