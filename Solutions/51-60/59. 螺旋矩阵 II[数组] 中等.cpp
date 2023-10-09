/*
** Problem: https://leetcode.cn/problems/spiral-matrix-ii/
** Article: https://memcpy0.blog.csdn.net/article/details/133715098
** Author: memcpy0
*/
// 写法1: 简单
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int c = 0, ns = n * n;
        int x = 0, y = -1;
        while (c < ns) {
            while (c < ns && y + 1 < n && !ans[x][y + 1]) 
                ans[x][++y] = ++c;
            while (c < ns && x + 1 < n && !ans[x + 1][y])
                ans[++x][y] = ++c;            
            while (c < ns && y - 1 >= 0 && !ans[x][y - 1])
                ans[x][--y] = ++c;
            while (c < ns && x - 1 >= 0 && !ans[x - 1][y])
                ans[--x][y] = ++c;
        }
        return ans;
    }
};
// 写法2
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int c = 0, ns = n * n;
        int x = 0;
        while (c < ns) {
            // 每次螺旋开始向右,y都等于x
            for (int y = x; y < n - x; ++y)
                ans[x][y] = ++c;
            // 向下
            for (int y = x + 1; y < n - x; ++y) 
                ans[y][n - x - 1] = ++c;
            // 向左
            for (int y = n - x - 2; y >= x; --y)
                ans[n - x - 1][y] = ++c;
            for (int y = n - x - 2; y > x; --y)
                ans[y][x] = ++c;
            ++x; // 加1层螺旋
        }
        return ans;
    }
};