class Solution {
public:
    /*用dq来做，从尾push_back新的数下标，如果头上下标出了window则删除，如果新的数比尾部的数大，
    则说明在接下来的windows里尾部现在的数都不会是maximum，可以直接删除，直到尾部的数比新数大
    为止
    每个数最多是入deque出deque一次，所以时间复杂度为O(n)*/
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if(k < 1 || nums.size() < k) return res;
        deque<int> dq;
        for(int i = 0; i < k; i++){
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        res.push_back(nums[dq.front()]);
        for(int i = k; i < nums.size(); i++){
            if(dq.front() < i - (k - 1)){
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            res.push_back(nums[dq.front()]);
        }
        return res;
    }
};
