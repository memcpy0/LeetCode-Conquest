/*
** Problem: https://leetcode.cn/problems/construct-product-matrix/
** Article: https://memcpy0.blog.csdn.net/article/details/133854911
** Author: memcpy0
*/
// BEST
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int MOD = 12345;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> p(n, vector<int>(m));
        long long suf = 1; // 后缀乘积
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                p[i][j] = suf; // p[i][j]先初始化为后缀乘积
                suf = suf * grid[i][j] % MOD;
            }
        }
        long long pre = 1; // 前缀乘积
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                p[i][j] = p[i][j] * pre % MOD; // 然后再乘上前缀乘积
                pre = pre * grid[i][j] % MOD;
            }
        }
        return p;
    }
};