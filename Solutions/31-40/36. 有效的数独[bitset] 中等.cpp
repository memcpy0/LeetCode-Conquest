/*
** Problem: https://leetcode-cn.com/problems/length-of-last-word/
** Article: https://memcpy0.blog.csdn.net/article/details/120580502
** Author: memcpy0
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //row[i][num],col[i][num]判断i行或i列中数字(num+1)是否出现
        //blocks[i][num]判断第i个3x3矩阵内数字(num+1)是否出现
        bitset<9> row[9], col[9], blocks[9];
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '1', blockIdk = i / 3 * 3 + j / 3;
                if (row[i][num] || col[j][num] || blocks[blockIdk][num]) return false;
                row[i][num] = col[j][num] = blocks[blockIdk][num] = true;
            }
        }
        return true;
    }
};