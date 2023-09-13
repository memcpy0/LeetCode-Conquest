/*
** Problem: https://leetcode.cn/problems/check-knight-tour-configuration
** Article: https://memcpy0.blog.csdn.net/article/details/132847698
** Author: memcpy0
*/
class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) return false;
        int n = grid.size();
        vector<array<int, 2>> indices(n * n);
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < n; ++j)
                indices[grid[i][j]] = {i, j};
        for (int i = 1; i < indices.size(); ++i) {
            int dx = abs(indices[i][0] - indices[i - 1][0]);
            int dy = abs(indices[i][1] - indices[i - 1][1]);
            if (dx * dy != 2) return false;
        }
        return true;
    }
};