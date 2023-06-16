/*
** Problem: https://leetcode.cn/problems/compare-strings-by-frequency-of-the-smallest-character
** Article: https://memcpy0.blog.csdn.net/article/details/109456008
** Author: memcpy0
*/
// BEST: 容斥原理+直接遍历
class Solution { 
    public int islandPerimeter(int[][] grid) {
        int ans = 0;
        for (int i = 0; i < grid.length; ++i) {
            for (int j = 0; j < grid[i].length; ++j) {
                if (grid[i][j] == 1) {
                    ans += 4;
                    if (i + 1 < grid.length && grid[i + 1][j] == 1) ans -= 2;
                    if (j + 1 < grid[i].length && grid[i][j + 1] == 1) ans -= 2;
                }
            }
        }
        return ans;
    }
}

// DFS+对陆地格子每条边看是否能算作岛屿周长
class Solution { 
    int[][] d = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int dfs(int[][] grid, int a, int b) {
        if (a < 0 || a >= grid.length || b < 0 || b >= grid[0].length || grid[a][b] == 0) return 1;
        if (grid[a][b] == 2) return 0;
        grid[a][b] = 2; // 标记已被访问
        int cnt = 0;
        for (int i = 0; i < 4; ++i) {
            int x = a + d[i][0], y = b + d[i][1];  
            cnt += dfs(grid, x, y); // 检查每条边,看能否算作岛屿周长
        } 
        return cnt;
    }
    public int islandPerimeter(int[][] grid) {
        for (int i = 0; i < grid.length; ++i)
            for (int j = 0; j < grid[i].length; ++j) 
                if (grid[i][j] == 1) // 不会再出现第二个为1的格子
                    return dfs(grid, i, j); 
        return 0;
    }
}