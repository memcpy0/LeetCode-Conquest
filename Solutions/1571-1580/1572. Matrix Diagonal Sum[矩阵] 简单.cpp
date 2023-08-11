/*
** Problem: https://leetcode.cn/problems/matrix-diagonal-sum/
** Article: https://memcpy0.blog.csdn.net/article/details/109633344
** Author: memcpy0
*/
// BEST: 最后减去交点值
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0, n = mat.size() - 1;
        for (int i = 0; i <= n; ++i) 
            ans += mat[i][i] + mat[i][n - i];
        return (n & 1) ? ans : ans - mat[n / 2][n / 2];
    }
};