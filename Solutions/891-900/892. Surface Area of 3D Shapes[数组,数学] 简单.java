/*
** Problem: https://leetcode.cn/problems/surface-area-of-3d-shapes/
** Article: https://memcpy0.blog.csdn.net/article/details/131258786
** Author: memcpy0
*/
class Solution {
    public int surfaceArea(int[][] grid) {
        int ans = 0;
        int n = grid.length, m = grid[0].length;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0) continue;
                // ans += grid[i][j] * 6 - (grid[i][j] - 1) * 2;
                ans += (grid[i][j] << 2) + 2;
                if (i + 1 < n && grid[i + 1][j] != 0) // 右边
                    ans -= Math.min(grid[i][j], grid[i + 1][j]) << 1;
                if (j + 1 < m && grid[i][j + 1] != 0) // 下边
                    ans -= Math.min(grid[i][j], grid[i][j + 1]) << 1;
            }
        }
        return ans;
    }
}

class Solution {
    public int surfaceArea(int[][] grid) {
        int blocks = 0, cover = 0; // 正方体的个数,盖住的面的个数
        int n = grid.length, m = grid[0].length;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0) continue; 
                blocks += grid[i][j];
                cover += grid[i][j] - 1;
                if (i + 1 < n && grid[i + 1][j] != 0) // 右边
                    cover += Math.min(grid[i][j], grid[i + 1][j]);
                if (j + 1 < m && grid[i][j + 1] != 0) // 下边
                    cover += Math.min(grid[i][j], grid[i][j + 1]);
            }
        }
        return blocks * 6 - cover * 2;
    }
}