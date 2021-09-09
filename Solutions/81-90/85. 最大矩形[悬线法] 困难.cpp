/*
** Problem: https://leetcode-cn.com/problems/maximal-rectangle/
** Article: https://memcpy0.blog.csdn.net/article/details/116775219
** Author: memcpy0
*/
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        using Matrix = vector<vector<int>>;
        using Row = vector<int>;
        Matrix u(m + 2, row(n + 2)), l(m + 2, row(n + 2)), r(m + 2, row(n + 2)); //便于处理边界
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (matrix[i - 1][j - 1] == '1') {
                    u[i][j] = u[i - 1][j] + 1;
                    l[i][j] = l[i][j - 1] + 1;
                }
            }
        }
        for (int i = 1; i <= m; ++i)
            for (int j = n; j >= 1; --j) 
                if (matrix[i - 1][j - 1] == '1') 
                    r[i][j] = r[i][j + 1] + 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (matrix[i - 1][j - 1] == '1') {
                    if (i > 1 && matrix[i - 2][j - 1] == '1') { //注意是字符
                        l[i][j] = min(l[i - 1][j], l[i][j]);
                        r[i][j] = min(r[i - 1][j], r[i][j]);
                    }
                    ans = max(ans, u[i][j] * (l[i][j] + r[i][j] - 1));
                }
            }
        }
        return ans;
    }   
};