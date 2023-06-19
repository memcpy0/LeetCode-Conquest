/*
** Problem: https://leetcode.cn/problems/number-of-closed-islands/
** Article: https://memcpy0.blog.csdn.net/article/details/131284911
** Author: memcpy0
*/
// BEST: DFS+出界标记
class Solution {
    private boolean closed;
    private void dfs(int[][] g, int i, int j) {
        if (i == 0 || i == g.length - 1 || j == 0 || j == g[i].length - 1) {
            if (g[i][j] == 0) closed = false; // 到达边界
            return;
        }
        if (g[i][j] != 0) return;
        g[i][j] = 1; // 标记(i,j)被访问,避免重复访问
        dfs(g, i - 1, j);
        dfs(g, i + 1, j);
        dfs(g, i, j - 1);
        dfs(g, i, j + 1);
    }

    public int closedIsland(int[][] grid) {
        int m = grid.length, n = grid[0].length, ans = 0;
        if (m < 3 || n < 3) return 0; // 特判
        for (int i = 1; i + 1 < m; ++i) {
            for (int j = 1; j + 1 < n; ++j) {
                if (grid[i][j] == 0) {
                    closed = true;
                    dfs(grid, i, j);
                    if (closed) ++ans; 
                }
            }
        }
        return ans;
    }
}

// DFS+由外到内
class Solution {
    private boolean closed;
    private void dfs(int[][] g, int i, int j) {
        if (i < 0 || i >= g.length || j < 0 || j >= g[i].length || g[i][j] != 0) 
            return; // 到达边界 
        g[i][j] = 1; // 标记(i,j)被访问,避免重复访问
        dfs(g, i - 1, j);
        dfs(g, i + 1, j);
        dfs(g, i, j - 1);
        dfs(g, i, j + 1);
    }

    public int closedIsland(int[][] grid) {
        int m = grid.length, n = grid[0].length, ans = 0;
        if (m < 3 || n < 3) return 0; // 特判
        for (int i = 0; i < m; ++i) {
            // 如果是第一行和最后一行,访问所有格子
            // 否则,只访问第一列和最后一列的格子
            int step = (i == 0 || i == m - 1) ? 1 : n - 1;
            for (int j = 0; j < n; j += step)
                dfs(grid, i, j);
        } 
        for (int i = 1; i + 1 < m; ++i) {
            for (int j = 1; j + 1 < n; ++j) {
                if (grid[i][j] == 0) { 
                    dfs(grid, i, j);
                    ++ans; // 一定是封闭岛屿 
                }
            }
        }
        return ans;
    }
}

// 并查集
class Solution {
    public int closedIsland(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        UnionFind uf = new UnionFind(m * n);
        for (int i = 0; i < m; ++i) { // 第一列和最后一列
            if (grid[i][0] == 0) uf.merge(i * n, 0);
            if (grid[i][n - 1] == 0) uf.merge(i * n + n - 1, 0);
        }
        for (int j = 1; j < n - 1; ++j) { // 第一行和最后一行
            if (grid[0][j] == 0) uf.merge(j, 0);
            if (grid[m - 1][j] == 0) uf.merge((m - 1) * n + j, 0);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) { // 如果一个陆地上和左有陆地,则连通
                    if (i > 0 && grid[i - 1][j] == 0)
                        uf.merge(i * n + j, (i - 1) * n + j);
                    if (j > 0 && grid[i][j - 1] == 0)
                        uf.merge(i * n + j, i * n + j - 1);
                }
            }
        }
        var cnt = new HashSet<Integer>();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 0)
                    cnt.add(uf.find(i * n + j));
        int total = cnt.size();
        if (cnt.contains(uf.find(0))) --total;
        return total;
    }
}
class UnionFind {
    private int[] parent;
    private int[] rank;
    public UnionFind(int n) {
        this.parent = new int[n];
        for (int i = 0; i < n; ++i) parent[i] = i;
        this.rank = new int[n]; // 每个集合的秩
    }
    public void merge(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx != ry) {
            if (rank[rx] > rank[ry]) parent[ry] = rx;
            else if (rank[rx] < rank[ry]) parent[rx] = ry;
            else { // 高度相同时
                parent[ry] = rx;
                ++rank[rx]; // 高度+1
            }
        }
    }
    public int find(int x) {
        return (parent[x] != x) ? (parent[x] = find(parent[x])) : parent[x];
    }
}