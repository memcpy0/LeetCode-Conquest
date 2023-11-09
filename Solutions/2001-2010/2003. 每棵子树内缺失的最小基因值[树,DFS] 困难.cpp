/*
** Problem: https://leetcode.cn/problems/find-mode-in-binary-search-tree/
** Article: https://memcpy0.blog.csdn.net/article/details/134173018
** Author: memcpy0
*/

class Solution {
private:
    vector<int> tree[100010]; //树 
    bool genes[100010], vis[100010]; //某个基因值是否出现,是否访问某个顶点
public:
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n = parents.size();
        for (int i = 1; i < n; ++i) tree[parents[i]].push_back(i); //0是根节点
        int pos = -1; //基因值1的下标位置
        for (int i = 0; i < n; ++i) if (nums[i] == 1) { pos = i; break; } 
        vector<int> ans(n, 1); //结果数组
        if (pos == -1) return ans; //不存在为1的基因值,全部返回1
        int last = 2; //遍历子树时如果基因值为last的顶点被访问,则++last
        function<void(int)> dfs = [&](int u) {
            if (vis[u]) return;
            vis[u] = true; //访问过这一顶点
            for (const int &v : tree[u]) dfs(v); //后根遍历
            genes[nums[u]] = true;   //标记nums[u]这一基因值的出现
            while (genes[last]) ++last; //出现last这一基因值,说明不再缺少last,++last
        };
        while (pos != -1) { //从基因值1的下标位置,沿着父节点一路上溯到根
            dfs(pos); //DFS遍历含有基因值1的子树
            ans[pos] = last; //得到当前(含有基因值1的)子树缺少的最小基因值
            pos = parents[pos]; //上溯
        }
        return ans;
    }
};