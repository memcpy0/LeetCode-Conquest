/*
** Problem: https://leetcode.cn/problems/can-make-palindrome-from-substring/
** Article: https://memcpy0.blog.csdn.net/article/details/131992941
** Author: memcpy0
*/
// 动态规划+拓扑排序
class Solution {
private:
    vector<vector<int>> g;
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        g.resize(n);
        vector<int> ind(n);
        for (vector<int>& r : relations) {
            int x = r[0] - 1, y = r[1] - 1;
            g[x].push_back(y); // 建图
            ++ind[y];
        }
        // 拓扑排序 
        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (ind[i] == 0) // 没有先修课
                q.push(i); 
        vector<int> dp(n);
        int ans = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop(); // u出队意味着u的所有先修课都上完了
            // 出队的顺序就是拓扑序
            dp[u] += time[u]; // 加上当前课程的时间就得到了最终的dp[u]
            ans = max(ans, dp[u]);
            for (int v : g[u]) {
                dp[v] = max(dp[u], dp[v]); // 更新dp[v]的所有先修课程耗时的最大值
                if (--ind[v] == 0) { // v的先修课已上完
                    q.push(v); 
                }
            }
        }
        return ans;
    }  
};
// BEST: 记忆化搜索
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        int mx = 0;
        vector<vector<int>> prev(n + 1);
        for (auto &r : relations) {
            int x = r[0], y = r[1];
            prev[y].emplace_back(x);
        }
        unordered_map<int, int> rec;
        function<int(int)> dp = [&](int i) -> int {
            if (!rec.count(i)) {
                int cur = 0;
                for (int p : prev[i]) cur = max(cur, dp(p));
                cur += time[i - 1];
                rec[i] = cur;
            }
            return rec[i];
        };
        for (int i = 1; i <= n; ++i) mx = max(mx, dp(i));
        return mx;
    }
};