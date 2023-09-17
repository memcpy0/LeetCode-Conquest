/*
** Problem: https://leetcode.cn/problems/valid-arrangement-of-pairs/
** Article: https://memcpy0.blog.csdn.net/article/details/132950772
** Author: memcpy0
*/
class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        // 存储图
        unordered_map<int, vector<int>> edges;
        // 存储入度和出度
        unordered_map<int, int> deg;
        for (const auto& p: pairs) {
            edges[p[0]].push_back(p[1]);
            ++deg[p[0]], --deg[p[1]];
        }
        // 深度优先搜索（Hierholzer算法）求解欧拉通路
        vector<vector<int>> ans;
        function<void(int)> dfs = [&](int u) {
            while (!edges[u].empty()) {
                int v = edges[u].back();
                edges[u].pop_back(); // 删除一条边
                dfs(v);
                ans.push_back({u, v});
            }
        };     
        // 寻找起始节点
        for (const auto& [x, occ]: deg) // 如果有节点出度比入度恰好多 1，那么只有它才能是起始节点
            if (occ == 1) {
                dfs(x);
                break;
            }
        if (ans.empty()) dfs(pairs[0][0]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};