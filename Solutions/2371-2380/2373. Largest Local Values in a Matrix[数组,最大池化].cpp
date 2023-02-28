/*
** Problem: https://leetcode.cn/problems/largest-local-values-in-a-matrix/
** Article: https://memcpy0.blog.csdn.net/article/details/129273468
** Author: memcpy0
*/


/*
class Solution {
private:
    int maxIn3x3(vector<vector<int>>& g, int i, int j) {
        int mx = 0;
        for (int x = i - 1; x < i + 2; ++x)
            for (int y = j - 1; y < j + 2; ++y)
                if (g[x][y] > mx) mx = g[x][y];
        return mx;
    }
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> ans(grid.size() - 2, vector<int>(grid.size() - 2));
        for (int i = 1, n = grid.size() - 1; i < n; ++i) 
            for (int j = 1; j < n; ++j) 
                ans[i - 1][j - 1] = maxIn3x3(grid, i , j);
        return ans;
    }
};
*/
class Solution { 
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size(), colMax[3];
        vector<vector<int>> ans(n - 2, vector<int>(n - 2));
        for (int i = 0; i < n - 2; ++i) {
            for (int k = 0; k <= 2; ++k)
                colMax[k] = max({ grid[i][k], grid[i + 1][k], grid[i + 2][k] });
            ans[i][0] = max({ colMax[0], colMax[1], colMax[2] });
            for (int j = 1; j < n - 2; ++j) {
                colMax[0] = colMax[1], colMax[1] = colMax[2];
                colMax[2] = max({ grid[i][j + 2], grid[i + 1][j + 2], grid[i + 2][j + 2] });
                ans[i][j] = max({ colMax[0], colMax[1], colMax[2] });
            }
        }
        return ans;
    }
};