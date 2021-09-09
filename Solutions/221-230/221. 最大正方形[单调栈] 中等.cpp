/*
** Problem: https://leetcode-cn.com/problems/maximal-square/
** Article: https://memcpy0.blog.csdn.net/article/details/120205494
** Author: memcpy0
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        vector<int> heights(n, 0);
        for (int i = 0; i < m; ++i) {
            stack<pair<int, int>> st; //height,width
            int maxArea = 0;
            for (int j = 0; j < n; ++j) 
                (matrix[i][j] == '1') ? (++heights[j]) : (heights[j] = 0);
            for (int j = 0; j <= n; ++j) {
                int totWidth = 0, height = j < n ? heights[j] : 0; //高度为0的哨兵
                while (!st.empty() && height < st.top().first) {
                    int h = st.top().first, w = st.top().second;
                    st.pop();
                    totWidth += w; 
                    int edge = min(h, totWidth); //正方形的边长
                    maxArea = max(maxArea, edge * edge);
                }
                st.push(pair<int, int>{height, totWidth + 1});
            }
            ans = max(ans, maxArea);
        }
        return ans;
    }
};