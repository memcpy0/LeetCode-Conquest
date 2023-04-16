/*
** Problem: https://leetcode.cn/problems/flower-planting-with-no-adjacent/ 
** Article: https://memcpy0.blog.csdn.net/article/details/130183609
** Author: memcpy0
*/
class Solution { 
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> g(n);
        vector<int> ans(n);
        for (vector<int> &v : paths) {
            g[v[0] - 1].push_back(v[1] - 1); // 从0开始
            g[v[1] - 1].push_back(v[0] - 1);
        } 
        for (int i = 0; i < n; ++i) { // 给结点i选择颜色
            int used = 1; // 由于颜色是1~4,把0加入mask保证下面不会算出0
            for (int j: g[i]) used |= 1 << ans[j];
            ans[i] = __builtin_ctz(~used);
        }
        return ans;
    }
}; 