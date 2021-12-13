/*
** Problem: https://leetcode-cn.com/problems/max-increase-to-keep-city-skyline/
** Article: https://memcpy0.blog.csdn.net/article/details/112853811
** Author: memcpy0
*/
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> ud, lr;
        int n = grid.size(), ans = 0;
        for (int i = 0; i < n; ++i) { //得到原始数组的天际线
            int colMaxVal = 0;
            for (int j = 0; j < n; ++j) colMaxVal = max(colMaxVal, grid[j][i]); //得到这一列的最大值
            ud.push_back(colMaxVal);
            lr.push_back(*max_element(grid[i].begin(), grid[i].end())); //得到这一行的最大值
        }
        for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) 
        	ans += min(lr[i], ud[j]) - grid[i][j]; 
        return ans;
    }
};