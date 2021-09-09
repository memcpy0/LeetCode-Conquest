/*
** Problem: https://leetcode-cn.com/problems/maximal-rectangle/
** Article: https://memcpy0.blog.csdn.net/article/details/116775219
** Author: memcpy0
*/
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        vector<int> heights(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) 
                matrix[i][j] == '0' ? (heights[j] = 0) : (heights[j] += 1); //连接到本层的柱子
            int maxArea = 0;
            vector<pair<int, int>> st;
            for (int j = 0; j <= n; ++j) {
                int height = j < n ? heights[j] : 0, width = 0; //最后多加一个0高度柱子作为哨兵
                while (!st.empty() && height < st.back().first) { //当前柱子高度更低,前面的柱子无法往右扩张 
                    width += st.back().second;
                    maxArea = max(maxArea, width * st.back().first); //前面的柱子形成的最大矩形面积可被计算
                    st.pop_back();
                }
                st.push_back({height, width + 1});
            }
            ans = max(ans, maxArea);
        }
        return ans;
    } 
};