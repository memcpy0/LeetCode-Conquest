/*
** Problem: https://leetcode-cn.com/problems/length-of-last-word/
** Article: https://memcpy0.blog.csdn.net/article/details/120580502
** Author: memcpy0
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9] = {0}, col[9] = {0}, blocks[9] = {0};
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                int u = board[i][j] - '1', b = i / 3 * 3 + j / 3;
                if (((row[i] >> u) & 1) || ((col[j] >> u) & 1) || ((blocks[b] >> u) & 1)) return false;
                row[i] |= (1 << u); col[j] |= (1 << u); blocks[b] |= (1 << u);
            }
        }
        return true;
    }
};