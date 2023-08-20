/*
** Problem: https://leetcode.cn/problems/01-matrix/
** Article: https://memcpy0.blog.csdn.net/article/details/132394887
** Author: memcpy0
*/
// BEST: 多源BFS
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int MAX_VALUE = m + n;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) q.push({i, j});
                else mat[i][j] = MAX_VALUE;
            }
        }
        int d[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int i = 0; i < 4; ++i) {
                int u = x + d[i][0], v = y + d[i][1];
                if (u >= 0 && u < m && v >= 0 && v < n && mat[x][y] + 1 < mat[u][v]) {
                    mat[u][v] = mat[x][y] + 1;
                    q.push({u, v});
                }
            }
        }
        return mat;
    }
};