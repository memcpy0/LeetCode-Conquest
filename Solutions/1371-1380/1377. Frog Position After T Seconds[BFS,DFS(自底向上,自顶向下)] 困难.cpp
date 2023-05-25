/*
** Problem: https://leetcode.cn/problems/frog-position-after-t-seconds/
** Article: https://memcpy0.blog.csdn.net/article/details/107210675
** Author: memcpy0
*/
// 自底向上
class Solution {
public:
    double frogPosition(int n, vector<vector<int>> &edges, int t, int target) {
        vector<vector<int>> g(n + 1);
        g[1] = {0}; // 减少额外判断的小技巧
        for (auto &e : edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x); // 建树
        }
        double ans = 0;
        function<long long(int, int, int)> dfs = [&](int x, int fa, int left_t) -> long long {
            // t秒后必须在target(恰好到达，或者target是叶子停在原地)
            if (left_t == 0) return x == target;
            if (x == target) return g[x].size() == 1;
            for (int y : g[x]) { // 遍历x的儿子y
                if (y != fa) { // y不能是父节点
                    auto prod = dfs(y, x, left_t - 1); // 寻找target
                    if (prod) return prod * (g[x].size() - 1); // 乘上儿子个数,并直接返回
                }
            }
            return 0; // 未找到target
        };
        auto prod = dfs(1, 0, t);
        return prod ? 1.0 / prod : 0;
    }
}; 

// 自顶向下
/* 
class Solution {
public:
    double frogPosition(int n, vector<vector<int>> &edges, int t, int target) {
        vector<vector<int>> g(n + 1);
        g[1] = {0}; // 减少额外判断的小技巧
        for (auto &e : edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x); // 建树
        }
        double ans = 0;
        function<bool(int, int, int, long long)> dfs = [&](int x, int fa, int left_t, long long prod) -> bool {
            // t秒后必须在target(恰好到达，或target是叶子节点、停在原地)
            if (x == target && (left_t == 0 || g[x].size() == 1)) {
                ans = 1.0 / prod;
                return true;
            }
            if (x == target || left_t == 0) return false;
            for (int y : g[x]) // 遍历x的儿子y
                if (y != fa && dfs(y, x, left_t - 1, prod * (g[x].size() - 1)))
                    return true; // 找到target就不再递归了
            return false; // 未找到target
        };
        dfs(1, 0, t, 1);
        return ans;
    }
};
*/

/*
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<int> g[110];
        long long p[110] = {0, 1}; // p[1] = 1 
        int fa[110] = {0}; // 父节点 fa[1] = 0
        g[1].push_back(0);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);  
            g[e[1]].push_back(e[0]);
        }
        queue<int> q;
        q.push(1); 
        while (!q.empty() && t >= 0) {
            int size = q.size(); 
            for (int i = 0; i < size; ++i) {
                int u = q.front(); q.pop();
                int cnt = g[u].size() - 1;
                if (u == target) {
                    if (t == 0) return 1.0 / p[u]; // 刚好到目标
                    else if (t > 0 && !cnt) return 1.0 / p[u]; // 此时还有时间且u为叶子
                    return 0; // 没有时间了
                } 
                for (auto v : g[u]) {
                    if (v == fa[u]) continue;
                    fa[v] = u; // 在遍历的过程中记录父节点(按照遍历顺序)
                    q.push(v); 
                    p[v] = p[u] * cnt;
                } 
            }
            --t; // 经过1秒 // t=0时说明被弹出的下一层节点就是能到达的最远节点
        }
        return 0;
    }
};
*/