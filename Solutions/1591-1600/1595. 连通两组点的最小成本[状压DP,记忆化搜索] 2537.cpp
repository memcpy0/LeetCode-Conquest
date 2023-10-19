/*
** Problem: https://leetcode.cn/problems/minimum-cost-to-connect-two-groups-of-points/
** Article: https://memcpy0.blog.csdn.net/article/details/133937714
** Author: memcpy0
*/
// BEST: 记忆化搜索
class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int n = cost.size(), m = cost[0].size();
        vector<int> minCost(m, INT_MAX);
        for (int j = 0; j < m; ++j)
            for (auto &c : cost)
                minCost[j] = min(minCost[j], c[j]);
        // 第一组的 0,1,...,i 和第二组的 0,1,...m-1 相连，且第二组的集合 j 中的元素未被连接时，最小成本是多少
        vector<vector<int>> memo(n, vector<int>(1 << m, INT_MAX));
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (i < 0) {
                int ans = 0;
                for (int k = 0; k < m; ++k)
                    if (j >> k & 1) // 第二组的点集中k未连接
                        ans += minCost[k]; // 去第一组找个成本最小的点连接
                return ans;
            }
            int &ans = memo[i][j]; // 引用
            if (ans != INT_MAX) return ans; // 之前算过了
            for (int k = 0; k < m; ++k) // 第一组的点i与第二组的点k
                ans = min(ans, dfs(i - 1, j & ~(1 << k)) + cost[i][k]);
            return ans;
        };
        return dfs(n - 1, (1 << m) - 1);
    }
};
// 递推
class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int n = cost.size(), m = cost[0].size();
        vector<int> minCost(m, INT_MAX);
        for (int j = 0; j < m; ++j)
            for (auto &c : cost)
                minCost[j] = min(minCost[j], c[j]);

        vector<vector<int>> f(n + 1, vector<int>(1 << m));
        for (int j = 0; j < 1 << m; ++j) 
            for (int k = 0; k < m; ++k)
                if (j >> k & 1) // 第二组的点k未连接
                    f[0][j] += minCost[k]; //去第一组找个成本最小的点连接
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 1 << m; ++j) {
                int ans = INT_MAX;
                for (int k = 0; k < m; ++k) // 第一组的点i与第二组的点k连接
                    ans = min(ans, f[i][j & ~(1 << k)] + cost[i][k]);
                f[i + 1][j] = ans;
            }
        }
        return f[n][(1 << m) - 1];
    }
};
// 时空最优
class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int n = cost.size(), m = cost[0].size();
        int f[1 << m];
        f[0] = 0;
        for (int j = 0; j < m; ++j) {
            int mn = INT_MAX;
            for (auto &c : cost) mn = min(mn, c[j]);
            int bit = 1 << j;
            for (int mask = 0; mask < bit; ++mask)
                f[bit | mask] = f[mask] + mn;
        }
        for (auto &row : cost) {
            for (int j = (1 << m) - 1; j >= 0; --j) {
                int ans = INT_MAX;
                for (int k = 0; k < m; ++k) // 第一组的点i与第二组的点k
                    ans = min(ans, f[j & ~(1 << k)] + row[k]);
                f[j] = ans;
            }
        }
        return f[(1 << m) - 1];
    }
};