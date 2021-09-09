/*
** Problem: https://leetcode-cn.com/problems/maximal-square/
** Article: https://memcpy0.blog.csdn.net/article/details/120205494
** Author: memcpy0
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> dp(n); 
        //dp[i][j]为以第i-1行第j-1列为右下角,能构成的最大的正方形边长
        //dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
        int pre = 0, temp = 0;
        int maxEdge = 0; //最长的正方形边长
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0 || matrix[i][j] == '0') { //注意边界情况
                    pre = dp[j]; dp[j] = matrix[i][j] - '0';
                } else { //此处原dp[j]指的是dp[i-1][j],dp[j-1]指的是dp[i][j-1],
                    temp = dp[j];
                    dp[j] = 1 + min(min(dp[j], dp[j - 1]), pre); //pre指的是dp[i-1][j-1]
                    pre = temp;
                }
                maxEdge = max(maxEdge, dp[j]);
            }
        }
        return maxEdge * maxEdge;
    } 
};