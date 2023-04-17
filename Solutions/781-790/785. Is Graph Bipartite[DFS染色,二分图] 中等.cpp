/*
** Problem: https://leetcode.cn/problems/is-graph-bipartite/
** Article: https://memcpy0.blog.csdn.net/article/details/130200391
** Author: memcpy0
*/
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n);
        function<bool(int, int)> dfs = [&](int i, int c) {
            color[i] = c; // 1,2表示访问过,0表示未访问
            for (int j : graph[i]) {
                if (!color[j] && dfs(j, 3 - c) == false) return false;
                else if (color[j] == color[i]) {  return false; }
            }
            return true;
        };
        for (int i = 0; i < n; ++i)
            if (!color[i] && dfs(i, 1) == false) return false;
        return true;
    }
};

