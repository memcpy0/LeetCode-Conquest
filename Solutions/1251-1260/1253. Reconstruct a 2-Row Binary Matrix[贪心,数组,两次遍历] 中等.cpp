/*
** Problem: https://leetcode.cn/problems/reconstruct-a-2-row-binary-matrix/
** Article: https://memcpy0.blog.csdn.net/article/details/131277765
** Author: memcpy0
*/
// 先贪心处理2的情况
class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        vector<vector<int>> ans(2, vector<int>(n)); 
        for (int j = 0; j < n; ++j) {
            if (colsum[j] == 2) {
                if (!upper || !lower) return {}; // 不够组成列
                ans[0][j] = ans[1][j] = 1;
                --upper, --lower;
            }
        }
        for (int j = 0; j < n; ++j) { 
            if (colsum[j] == 1) {
                if (!upper && !lower) return {}; // 不够组成列
                if (upper) ans[0][j] = 1, --upper;
                else ans[1][j] = 1, --lower;
            }
        } 
        if (!lower && !upper) return ans;
        return {}; // 不够组成列   
    }
};

// 先检查colsum是否有解
class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        vector<vector<int>> ans(2, vector<int>(n)); 
        int sum = 0, two = 0; // two为colsum中2的个数
        for (int j = 0; j < n; ++j) {
            if (colsum[j] == 2) ++two; 
            sum += colsum[j];
        }
        if (sum != upper + lower || min(upper, lower) < two) return {};
        upper -= two, lower -= two; // 相当于先处理2的情况
        for (int j = 0; j < n; ++j) { 
            if (colsum[j] == 2) ans[0][j] = ans[1][j] = 1;
            else if (colsum[j] == 1) { 
                if (upper) ans[0][j] = 1, --upper;
                else ans[1][j] = 1;
            }
        } 
        return ans;
    }
};