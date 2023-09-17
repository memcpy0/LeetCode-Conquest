/*
** Problem: https://leetcode.cn/problems/shortest-path-visiting-all-nodes
** Article: https://memcpy0.blog.csdn.net/article/details/132941894
** Author: memcpy0
*/
// BEST: BFS+状态压缩+走完所有节点的最短路
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& g) {
        int n = g.size();
        queue<tuple<int, int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(1 << n)); // [u,mask],避免重复遍历
        for (int i = 0; i < n; ++i) {
            q.emplace(i, 1 << i, 0);
            vis[i][1 << i] = true;
        }
        int ans = 0;
        while (!q.empty()) {
            auto [u, mask, dist] = q.front();
            q.pop();
            if (mask == (1 << n) - 1) {
                ans = dist;
                break;
            }
            // 搜索相邻的节点
            for (int v : g[u]) {
                // 将mask的第v位置1
                int maskV = mask | (1 << v);
                if (!vis[v][maskV]) {
                    q.emplace(v, maskV, dist + 1);
                    vis[v][maskV] = true;
                }
            }
        }
        return ans;
    }
};
// 状态压缩+Floyd+动态规划
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& g) {
        int n = g.size();
        vector<vector<int>> d(n, vector<int>(n, n + 1));
        for (int i = 0; i < n; ++i) for (int j : g[i]) 
            d[i][j] = 1;
        // 使用floyd算法预处理出所有点对之间的最短路径长度
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        vector<vector<int>> f(n, vector<int>(1 << n, INT_MAX / 2));
        for (int mask = 1; mask < (1 << n); ++mask) {
            // 如果mask只包含一个1，即是2的幂
            if ((mask & (mask - 1)) == 0) {
                int u = __builtin_ctz(mask);
                f[u][mask] = 0; // 从某一点开始到u为止,经过的关键节点对应的二进制表示为mask时的最短路径长度
            } else {
                for (int u = 0; u < n; ++u) {
                    if (mask & (1 << u)) { // 如果经过了点u
                        for (int v = 0; v < n; ++v) { // 枚举上一个关键节点
                            if ((mask & (1 << v)) && u != v)
                                f[u][mask] = min(f[u][mask], f[v][mask ^ (1 << u)] 
                                    + d[v][u]);
                        }
                    }
                }
            }
        }
        int ans = INT_MAX;
        for (int u = 0; u < n; ++u) ans = min(ans, f[u][(1 << n) - 1]);
        return ans;
    }
};