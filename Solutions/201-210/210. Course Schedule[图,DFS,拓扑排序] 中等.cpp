/*
** Problem: https://leetcode.cn/problems/course-schedule-ii
** Article: https://memcpy0.blog.csdn.net/article/details/110391801
** Author: memcpy0
*/
class Solution {
private:
    vector<vector<int>> edges;
    vector<int> visited;
    vector<int> result; // 数组模拟栈,n-1为栈底,0为栈顶
    int index;
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
        result[--index] = u;
        return false; // 无环
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        result.resize(numCourses);
        index = numCourses;
        for (const auto& info: prerequisites)
            edges[info[1]].push_back(info[0]);
        for (int i = 0; i < numCourses; ++i)
            if (!visited[i])
                if (dfs(i)) return {}; // 有环时返回空
        return result;
    }
};
// BEST: BFS拓扑排序
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> G[numCourses], in(numCourses, 0);
        vector<int> result;
        for (const vector<int>& v : prerequisites) {
            ++in[v[0]]; // v[0] <- v[1]
            G[v[1]].push_back(v[0]);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) if (!in[i]) { q.push(i); result.push_back(i); }
        int count = 0; //拓扑序列中课程的数量
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (const int &v : G[u]) if (!(--in[v])) { q.push(v); result.push_back(v); }
        }
        return result.size() != numCourses ? vector<int>{} : result;
    }
}; 