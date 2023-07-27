/*
** Problem: https://leetcode.cn/problems/delete-greatest-value-in-each-row/
** Article: https://memcpy0.blog.csdn.net/article/details/131958407
** Author: memcpy0
*/
// BEST: 排序
class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) { 
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) sort(grid[i].begin(), grid[i].end());
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            int mx = grid[0][i];
            for (int j = 1; j < m; ++j) mx = max(mx, grid[j][i]);
            ans += mx;
        }
        return ans;
    }
};