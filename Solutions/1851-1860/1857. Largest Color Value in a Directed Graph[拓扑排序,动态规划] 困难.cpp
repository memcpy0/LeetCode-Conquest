/*
** Problem: https://leetcode.cn/problems/largest-color-value-in-a-directed-graph/
** Article: https://memcpy0.blog.csdn.net/article/details/131996938
** Author: memcpy0
*/
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int> g[n];
        vector<int> ind(n); // 节点的入度统计，用于找出拓扑排序中最开始的节点
        for (vector<int>& e : edges) {
            g[e[0]].push_back(e[1]);
            ++ind[e[1]];
        }
        vector<array<int, 26>> dp(n);
        int found = 0, ans = 0;
        queue<int> q;
        for (int i = 0; i < n; ++i) if (ind[i] == 0) q.push(i); 
        while (!q.empty()) {
            int u = q.front(); q.pop();
            ++found;
            ++dp[u][colors[u] - 'a']; // 节点u对应的颜色+1
            ans = max(ans, dp[u][colors[u] - 'a']);
            for (int v : g[u]) {
                for (int c = 0; c < 26; ++c)
                    dp[v][c] = max(dp[u][c], dp[v][c]);
                if (--ind[v] == 0) q.push(v);
            } 
        } 
        return found != n ? -1 : ans;
    }
};