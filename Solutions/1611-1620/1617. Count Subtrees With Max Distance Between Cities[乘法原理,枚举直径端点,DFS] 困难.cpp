/*
** Problem: https://leetcode.cn/problems/count-subtrees-with-max-distance-between-cities/
** Article: https://memcpy0.blog.csdn.net/article/details/129484058
** Author: memcpy0
*/
// n次DFS/BFS+乘法原理
class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            int x = e[0] - 1, y = e[1] - 1; // 编号改为从0开始
            g[x].push_back(y);
            g[y].push_back(x);
        }
        int dis[n][n]; memset(dis, 0, sizeof(dis)); // d[i][j]表示树中i到j的距离
        function<void(int, int, int)> dfs = [&](int i, int x, int fa) { // DFS遍历树的写法
            for (int y : g[x]) {
                if (y != fa) {
                    dis[i][y] = dis[i][x] + 1; // 自顶向下
                    dfs(i, y, x); 
                }
            }
        };
        for (int i = 0; i < n; ++i) // 原树是连通的
            dfs(i, i, -1); // 计算i到其余点的距离
        
        function<int(int, int, int, int, int)> dfs2 = [&](int i, int j, int d, int x, int fa) { // 计算以i,j为直径,d为直径长度,fa为x父节点时,x节点及其子树的选择方案数
            // 能递归到这,说明x可选
            int cnt = 1; // 选x但还没选子树
            for (int y : g[x]) {
                if (y != fa &&
                    (dis[i][y] < d || dis[i][y] == d && y > j) &&
                    (dis[j][y] < d || dis[j][y] == d && y > i)
                ) // 满足这些条件就可以选
                    cnt *= dfs2(i, j, d, y, x); // 每棵子树互相独立,乘法原理
            }
            if (dis[i][x] + dis[j][x] > d) // x是可选点,排除了dis[i][x]+dis[j][x]==d的必选点
                ++cnt; // 不选x
            return cnt;
        };

        vector<int> ans(n - 1);
        for (int i = 0; i < n; ++i) // 枚举直径端点
            for (int j = i + 1; j < n; ++j) 
                ans[dis[i][j] - 1] += dfs2(i, j, dis[i][j], i, -1);
        return ans;
    }
};