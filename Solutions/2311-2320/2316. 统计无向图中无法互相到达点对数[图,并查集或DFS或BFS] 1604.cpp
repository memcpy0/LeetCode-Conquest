/*
** Problem: https://leetcode.cn/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/
** Article: https://memcpy0.blog.csdn.net/article/details/133973599
** Author: memcpy0
*/
// BEST: DFS
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (vector<int>& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<bool> vis(n);
        function<int(int)> dfs = [&](int x) -> int {
            vis[x] = true; // 避免重复访问同个点
            int size = 1;
            for (int y : g[x]) if (!vis[y]) size += dfs(y);
            return size;
        };
        long long ans = 0, total = 0;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) { // 找到一个新连通块
                int size = dfs(i);
                ans += total * size;
                total += size;
            }
        }
        return ans;
    }
};