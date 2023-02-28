/*
** Problem: https://leetcode-cn.com/problems/the-time-when-the-network-becomes-idle/
** Article: https://memcpy0.blog.csdn.net/article/details/123624797
** Author: memcpy0
*/
class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>> g(patience.size());
        vector<int> dist(n, -1);
        // 建图
        for (const auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        // BFS求结点0到其他结点的最短距离
        queue<int> q;
        q.push(0);
        dist[0] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (const int &v : g[u]) 
                if (dist[v] == -1) { q.push(v); dist[v] = dist[u] + 1; }
        }
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            int rtt = 2 * dist[i]; // patience[i] >= 2*dist[i] 时, 不会重发消息, 对应的lastSent = 0
            int lastSent = (rtt - 1) / patience[i] * patience[i];
            ans = max(ans, lastSent + rtt);
        }
        return ans + 1;
    }
};