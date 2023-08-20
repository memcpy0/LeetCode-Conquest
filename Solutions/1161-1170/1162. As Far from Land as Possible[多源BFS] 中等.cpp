/*
** Problem: https://leetcode.cn/problems/as-far-from-land-as-possible/
** Article: https://memcpy0.blog.csdn.net/article/details/132395000
** Author: memcpy0
*/
// BEST: 多源BFS
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        int MAX_VALUE = n + n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    q.push({i, j});
                } else grid[i][j] = MAX_VALUE;
            }
        }
        int d[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
        int ans = -1;
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int i = 0; i < 4; ++i) {
                int u = x + d[i][0], v = y + d[i][1];
                if (u >= 0 && u < n && v >= 0 && v < n && grid[x][y] + 1 < grid[u][v]) {
                    // 只有海洋单元格的值会被更新,且一次性更新为到最近陆地单元格的距离
                    grid[u][v] = grid[x][y] + 1;
                    ans = max(ans, grid[u][v]);
                    q.push({u, v});
                }
            }
        }
        return ans;
    }
};