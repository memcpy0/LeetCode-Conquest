/*
** Problem: https://leetcode.cn/problems/course-schedule-iv/
** Article: https://memcpy0.blog.csdn.net/article/details/116947696
** Author: memcpy0
*/
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> g[numCourses];
        for (const vector<int> &pre : prerequisites) g[pre[0]].push_back(pre[1]);
        vector<vector<bool>> reachable(numCourses, vector<bool>(numCourses, false));
        for (int i = 0; i < numCourses; ++i) {
            queue<int> q;
            vector<bool> vis(numCourses, false);
            q.push(i);
            vis[i] = true;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                reachable[i][u] = true; //由i可达u
                for (const int &v : g[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
        }
        vector<bool> ans;
        for (const vector<int> &q : queries) ans.push_back(reachable[q[0]][q[1]]);
        return ans;
    }
};
// BEST写法,但不是BEST算法
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> reachable(numCourses, vector<bool>(numCourses, false));
        for (const vector<int> &pre : prerequisites) reachable[pre[0]][pre[1]] = true; //直接用邻接矩阵存储图
        for (int k = 0; k < numCourses; ++k) {
            for (int i = 0; i < numCourses; ++i) {
                if (!reachable[i][k]) continue; //剪枝,i不可达k
                for (int j = 0; j < numCourses; ++j)
                    reachable[i][j] = reachable[i][j] || reachable[k][j]; //i可达j或者i通过k可达j
            }
        }
        vector<bool> ans;
        for (const vector<int> &q : queries) ans.push_back(reachable[q[0]][q[1]]);
        return ans;
    }
};