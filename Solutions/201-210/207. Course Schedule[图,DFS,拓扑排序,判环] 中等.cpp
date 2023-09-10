/*
** Problem: https://leetcode.cn/problems/course-schedule
** Article: https://memcpy0.blog.csdn.net/article/details/110391696
** Author: memcpy0
*/
// DFS判断环
class Solution {
private:
    vector<vector<int>> edges;
    vector<int> visited;
public:
    bool dfs(int u) {
        visited[u] = 1; // 搜索中
        for (int v: edges[u]) {
            if (visited[v] == 0) { // 未搜索
                if (dfs(v)) return true; // 有环
            }
            else if (visited[v] == 1) // 搜索中
                return true; // 有环
        }
        visited[u] = 2;
        return false; // 无环
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto& info: prerequisites)
            edges[info[1]].push_back(info[0]);
        for (int i = 0; i < numCourses; ++i)
            if (!visited[i])
                if (dfs(i)) return false;
        return true;
    }
};
// BEST: BFS拓扑排序判断环
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> G[numCourses], in(numCourses, 0);
        for (const vector<int>& v : prerequisites) {
            ++in[v[0]]; // v[0] <- v[1]
            G[v[1]].push_back(v[0]);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) if (!in[i]) q.push(i);
        int count = 0; //拓扑序列中课程的数量
        while (!q.empty()) {
            int u = q.front(); q.pop();
            ++count;
            for (const int &v : G[u]) if (!(--in[v])) q.push(v);
        }
        return count == numCourses;
    }
};