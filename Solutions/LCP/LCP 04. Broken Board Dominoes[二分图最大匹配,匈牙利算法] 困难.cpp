/*
** Problem: https://leetcode.cn/problems/broken-board-dominoes
** Article: https://memcpy0.blog.csdn.net/article/details/130256180
** Author: memcpy0
*/
class Solution { 
public:
    int domino(int n, int m, vector<vector<int>>& broken) {
        vector<int> g[100];
        bool vis[100] = {false};
        bool b[100] = {false};
        int match[100];
        int ans = 0; 
        function<bool(int)> dfs = [&](int u) -> bool {
            for (int v : g[u]) { 
                if (!vis[v]) { // 没访问过
                    vis[v] = true; // 避免重复访问, 能让就让
                    if (match[v] == -1 || dfs(match[v])) {
                        match[v] = u; return true;
                    }
                }  
            }
            return false;
        };
        for (vector<int> &bv : broken) // 哪些位置破损 
            b[bv[0] * m + bv[1]] = true; 
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int u = i * m + j;
                if (b[u]) continue;
                int v1 = i * m + j + 1, v2 = (i + 1) * m + j;
                if (j + 1 < m && !b[v1]) { // 只存奇数点到偶数点的边也行
                    g[u].push_back(v1);
                    g[v1].push_back(u);
                }
                if (i + 1 < n && !b[v2]) { 
                    g[u].push_back(v2);
                    g[v2].push_back(u);
                }
            }
        }
        memset(match, -1, sizeof(match));
        for (int i = 0, t = n * m; i < t; ++i) {
            int x = i / m, y = i % m;
            memset(vis, false, size(vis));
            if (((x + y) & 1) && !b[i] && !vis[i] && dfs(i)) // 从奇数点出发向偶数点连边
                ++ans;
        }
        return ans;
    }
}; 