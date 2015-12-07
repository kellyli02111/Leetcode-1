class Solution {
public:
    int uniquePaths(int m, int n) {
        if ((m==1) || (n==1)) return 1;
        return uniquePaths(m-1,n)+uniquePaths(m,n-1);
    }
};
//递归：时间O(exp), 空间O(n) (递归每一个branch算完返回会自动释放内存)
