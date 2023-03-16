/*
** Problem: https://leetcode.cn/problems/find-valid-matrix-given-row-and-column-sums
** Article: https://memcpy0.blog.csdn.net/article/details/129590637
** Author: memcpy0
*/

/*
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size(), m = colSum.size();
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= ans[i][j];
                colSum[j] -= ans[i][j];
            }
        }
        return ans;
    }
};
*/

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size(), m = colSum.size();
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0, j = 0; i < n && j < m;) {
	        int rs = rowSum[i], cs = colSum[j];
	        if (rs < cs) { // 取rowsum[i],去掉第i行,往下走
		        colSum[j] -= rs;
		        ans[i++][j] = rs;
	        } else { // 去掉第j列,往右走
		        rowSum[i] -= cs;
		        ans[i][j++] = cs;
	        }
        }
        return ans;
    }
};