/*
** Problem: https://leetcode.cn/problems/pond-sizes-lcci/
** Article: https://memcpy0.blog.csdn.net/article/details/110848072
** Author: memcpy0
*/

// BEST: DFS
class Solution {
private:
    int m, n; 
    int dfs(vector<vector<int>>& land, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || land[i][j] != 0) return 0;
        land[i][j] = 1;
        return 1 + dfs(land, i - 1, j) + dfs(land, i + 1, j) + dfs(land, i, j - 1) + dfs(land, i, j + 1)
        + dfs(land, i - 1, j - 1) + dfs(land, i - 1, j + 1) + dfs(land, i + 1, j - 1) + dfs(land, i + 1, j + 1);
    }
public:
    vector<int> pondSizes(vector<vector<int>>& land) { 
        m = land.size(), n = land[0].size(); 
        vector<int> ans;
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                if (land[i][j] == 0)
                    ans.push_back(dfs(land, i, j));
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// BFS
class Solution { 
public:
    vector<int> pondSizes(vector<vector<int>>& land) { 
        int m = land.size(), n = land[0].size(); 
        vector<int> ans;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (land[i][j] == 0) {
                    int area = 0;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    land[i][j] = 1;
                    while (!q.empty()) {
                        auto [x, y] = q.front(); q.pop();
                        ++area;
                        for (int dx = -1; dx <= 1; ++dx) {
                            for (int dy = -1; dy <= 1; ++dy) {
                                if (dx == 0 && dy == 0) continue;
                                int tx = x + dx, ty = y + dy;
                                if (tx < 0 || tx >= m || ty < 0 || ty >= n || land[tx][ty] != 0) continue;
                                land[tx][ty] = 1;
                                q.push({tx, ty});
                            }

                        }
                    } 
                    ans.push_back(area);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};