/*
** Problem: https://leetcode.cn/problems/count-subtrees-with-max-distance-between-cities/
** Article: https://memcpy0.blog.csdn.net/article/details/129484058
** Author: memcpy0
*/
class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            int x = e[0] - 1, y = e[1] - 1; // 编号改为从0开始
            g[x].push_back(y);
            g[y].push_back(x);
        }
        vector<int> ans(n - 1);
        // 二进制枚举
        int tot = 1 << n;
        for (int mask = 3; mask < tot; ++mask) { // 至少需要两个点
            if ((mask & (mask - 1)) == 0) continue; // 少于两个点被选择,剪去一部分集合
            // 求树的直径
            int vis = 0, diameter = 0;
            function<int(int)> dfs = [&](int x) -> int {
                vis |= 1 << x; // 标记x被访问过
                int dx = 0;
                for (int y : g[x]) {
                    if ((vis >> y & 1) == 0 && mask >> y & 1) { // y没有访问且在mask集合中
                        int dy = dfs(y) + 1;
                        diameter = max(diameter, dy + dx);
                        dx = max(dx, dy);
                    }
                }
                return dx;
            };
            dfs(__builtin_ctz(mask)); // 从一个在mask中的点开始递归
            if (vis == mask)
                ++ans[diameter - 1];
        }
        return ans;
    }
};