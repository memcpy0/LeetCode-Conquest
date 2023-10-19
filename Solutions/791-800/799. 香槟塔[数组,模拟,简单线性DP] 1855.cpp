/*
** Problem: https://leetcode.cn/problems/champagne-tower/
** Article: https://memcpy0.blog.csdn.net/article/details/133937990
** Author: memcpy0
*/
// BEST
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> row = {(double)poured};
        for (int i = 1; i <= query_row; i++) {
            vector<double> nextRow(i + 1, 0.0);
            for (int j = 0; j < row.size(); j++) {
                double volume = row[j];
                if (volume > 1) {
                    nextRow[j] += (volume - 1) / 2;
                    nextRow[j + 1] += (volume - 1) / 2;
                }
            }
            row = nextRow;
        }            
        return min(1.0, row[query_glass]);
    }
};