class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res = 0;
        int n = nums.size();
        vector<int> numsNew;
        for (int i=0;i<n;i++){
            if (val != nums[i]){
                numsNew.push_back(nums[i]);
                res++;
            }
        }
        n = numsNew.size();
        for (int i = 0; i<n; i++){
            nums[i] = numsNew[i];
        }
        return res;
    }
};

/*size最好在外面找好 赋值给int,  不要在里面找，防止出错 提高效率
size() 这种函数的返回值默认是unsigned int, -1会溢出
不同类型的数据不要一起算
vector的用法
size()
push_back()往屁股后面加东西
用vector[] 可以引用或修改任何一项
*/
